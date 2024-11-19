import random

def is_prime(num):
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def gcd(a, b):
    """Calculate the greatest common divisor of two numbers."""
    while b!= 0:
        a, b = b, a % b
    return a

def multiplicative_inverse(a, m):
    """Calculate the multiplicative inverse of a modulo m."""
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        else:
            gcd, x, y = extended_gcd(b % a, a)
            return gcd, y - (b // a) * x, x

    gcd, x, _ = extended_gcd(a, m)
    if gcd!= 1:
        raise ValueError("a and m are not coprime")
    return x % m

def sign_message(p, alpha, a, beta, x, k, v):
    """Sign a message using the ElGamal signature scheme."""
    r = pow(alpha, k, p)
    s = (v - x * r) * multiplicative_inverse(k, p - 1) % (p - 1)
    return (r, s)

def verify_signature(p, alpha, a, beta, r, s, v):
    """Verify a signature using the ElGamal signature scheme."""
    v1 = pow(alpha, v, p)
    v2 = (pow(beta, r, p) * pow(r, s, p)) % p
    return v1 == v2


p = int(input("Enter a prime number p: "))
while not is_prime(p):
    p = int(input("Invalid input. Enter a prime number p: "))

alpha = int(input("Enter the generator alpha: "))
a = int(input("Enter the private key a: "))
beta = int(input("Enter the public key beta: "))
x = int(input("Enter the private key x: "))
k = int(input("Enter the random number k: "))
v = int(input("Enter the message v: "))


r, s = sign_message(p, alpha, a, beta, x, k, v)
print("Signature: ", (r, s))



gamma = (alpha ** k)%p
for i in range (p):
    if (k * i)% (p-1) ==1 :
        k_inv = i
        break
delta = ((v - a * gamma)* k_inv)%(p-1)

check1 = ((beta ** gamma ) * (gamma ** delta))% p
check2 = (alpha ** v)% p

# Verify the signature
if check1 == check2: 
    print("Signature is valid")
else:
    print("Signature is invalid")