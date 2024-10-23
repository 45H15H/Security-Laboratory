
# Q3. Write a program to implement RSA Algorithm.

from math import gcd

p, q = (map(int, input("Enter two distinct large prime numbers: ").split()))

print(f"n = p x q")
print(f"n = {p} x {q}")
n = p * q
print(f"n = {n}")

def euler_totient(p, q):
    """
    As p and q are prime numbers we can calculate Euler Totient using (p - 1) * (q - 1)
    """
    phi = (p - 1) * (q - 1)
    return phi

print(f"\nphi(n) = (p - 1) x (q - 1)")
print(f"phi({n}) = ({p} - 1) x ({q} - 1)")
phi = euler_totient(p, q)
print(f"phi({n}) = {phi}")

e = int(input(f"\nChoose an integer such that 1 < e < {phi} and e and {phi} are coprime: "))

print(f"\nd, such that (d * {e} mod {phi} = 1)")
d = 1
while (e * d) % phi != 1:
    d += 1
print(f"d = {d}")

print("\nEncryption: ")
print(f"Public key: <{e}, {n}>")
m = int(input("Messaage represented as a number: "))
print(f"Ciphertext: C = M ^ e mod n")
print(f"Ciphertext: C = {m} ^ {e} mod {n}")
c = m ** e % n
print(f"Ciphertext: C = {c}")

print("\nDecryption: ")
print(f"Private key: <{d}, {n}>")
print(f"Ciphertext represented as a number: {c}")
print(f"Plaintext: M = C ^ d mod n")
print(f"Plaintext: M = {c} ^ {d} mod {n}")
m = c ** d % n
print(f"Plaintext: M = {m}")