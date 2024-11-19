import random
import math

def is_prime(num):
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def gcd(a, b):
    """Calculate the greatest common divisor of two numbers."""
    while b!= 0:
        a, b = b, a % b
    return a

def multiplicative_inverse(e, phi):
    """Calculate the multiplicative inverse of e modulo phi."""
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        else:
            gcd, x, y = extended_gcd(b % a, a)
            return gcd, y - (b // a) * x, x

    gcd, x, _ = extended_gcd(e, phi)
    if gcd!= 1:
        raise ValueError("e and phi are not coprime")
    return x % phi

def generate_keypair(p, q):
    """Generate a public and private key pair."""
    n = p * q
    phi = (p - 1) * (q - 1)

    
    e = random.randrange(1, phi)
    while gcd(e, phi)!= 1:
        e = random.randrange(1, phi)

   
    d = multiplicative_inverse(e, phi)

    
    return ((e, n), (d, n))

def sign_message(message, private_key):
    """Sign a message using the private key."""
    d, n = private_key
    signature = [pow(ord(char), d, n) for char in message]
    return signature

def verify_signature(signature, message, public_key):
    """Verify a signature using the public key."""
    e, n = public_key
    for i in range(len(message)):
        if pow(signature[i], e, n)!= ord(message[i]):
            return False
    return True


p = int(input("Enter a prime number p: "))
q = int(input("Enter a prime number q: "))


public_key, private_key = generate_keypair(p, q)


message = input("Enter a message to sign: ")


signature = sign_message(message, private_key)


if verify_signature(signature, message, public_key):
    print("Signature is valid")
else:
    print("Signature is invalid")