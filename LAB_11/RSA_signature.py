# Implement RSA Signature Algorithm.

import math

# Function for modular exponentiation
def Modular_Expo(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

# Function for calculating modular inverse using the Extended Euclidean Algorithm
def MI_EEA(a, m):
    m0, y, x = m, 0, 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        m, a = a, m % a
        y, x = x - q * y, y
    return x + m0 if x < 0 else x

p = int(input('Enter prime-1: '))
q = int(input('Enter prime-2: '))
msg = input('Enter message: ')
msg = msg.upper()

def RSA_encrypt(msg, e, n):
    m = ''
    for c in msg:
        num = ord(c) - 64
        m += str(num).zfill(2)  # Zero pad to handle multi-digit numbers
    num = int(m)
    encrypt = Modular_Expo(num, e, n)
    return encrypt

def RSA_decrypt(num, d, n):
    text = Modular_Expo(num, d, n)
    decrypt = str(text)
    plain = ''
    for i in range(0, len(decrypt), 2):
        num = int(decrypt[i:i+2])
        num += 64
        plain += chr(num)
    return plain

def RSA_sign(msg, d, n):
    m = ''
    for c in msg:
        num = ord(c) - 64
        m += str(num).zfill(2)
    num = int(m)
    signature = Modular_Expo(num, d, n)
    return signature

def RSA_verify(msg, signature, e, n):
    m = ''
    for c in msg:
        num = ord(c) - 64
        m += str(num).zfill(2)
    num = int(m)
    verify = Modular_Expo(signature, e, n)
    return verify == num

n = p * q
phi = (p - 1) * (q - 1)
e = 0
for i in range(2, phi):
    if math.gcd(i, phi) == 1:
        e = i
        break
d = MI_EEA(e, phi)

print('Public Key:', n, e)
print('Private Key:', p, q, d)

signature = RSA_sign(msg, d, n)
print('Signature:', signature)

is_valid = RSA_verify(msg, signature, e, n)
print('Is the signature valid?', is_valid)

num = RSA_encrypt(msg, e, n)
print('Encrypted message:', num)
plain = RSA_decrypt(num, d, n)
print('Decrypted message:', plain)
