# 21CSE1003 Ashish Singh

# Implement Elgamal digital Signature Algorithm.

from math import gcd

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

# ElGamal Key Generation
def key_generation():
    p = 467  # Should be a large prime number
    g = 2
    x = 3
    y = mod_exp(g, x, p)  # Public key component y = g^x % p
    print(y)
    return p, g, y, x

# ElGamal Signature Generation
def sign(message, p, g, x):
    from hashlib import sha256
    import random
    k = random.randint(1, p-2)
    while gcd(k, p-1) != 1:
        k = random.randint(1, p-2)
    
    r = mod_exp(g, k, p)
    k_inv = mod_exp(k, p - 2, p - 1)
    m_hash = int(sha256(message.encode()).hexdigest(), 16)
    s = (k_inv * (m_hash - x * r)) % (p - 1)
    
    return r, s

# ElGamal Signature Verification
def verify(message, signature, p, g, y):
    from hashlib import sha256
    r, s = signature
    if not (0 < r < p and 0 < s < p - 1):
        return False
    
    m_hash = int(sha256(message.encode()).hexdigest(), 16)
    v1 = mod_exp(g, m_hash, p)
    v2 = (mod_exp(y, r, p) * mod_exp(r, s, p)) % p
    
    return v1 == v2

if __name__ == "__main__":
    p, g, y, x = key_generation()
    print(f"Public Key (p, g, y): ({p}, {g}, {y})")
    print(f"Private Key (x): {x}")

    message = input("Enter the message to sign: ")
    
    signature = sign(message, p, g, x)
    print(f"Signature (r, s): {signature}")
    
    is_valid = verify(message, signature, p, g, y)
    print(f"Is the signature valid? {is_valid}")
