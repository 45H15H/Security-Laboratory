
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
    p = 9
    g = 2
    x = 3
    y = mod_exp(g, x, p)  # Public key component y = g^x % p
    return p, g, y, x

# ElGamal Encryption
def encrypt(m, p, g, y):
    k = 4 
    c1 = mod_exp(g, k, p)
    c2 = (m * mod_exp(y, k, p))
    return c1, c2

# ElGamal Decryption
def decrypt(ciphertext, p, x):
    c1, c2 = ciphertext
    s = mod_exp(c1, x, p)       
    s_inv = mod_exp(s, p - 2, p)
    m = (c2 * s_inv) % p        
    return m

if __name__ == "__main__":
    p, g, y, x = key_generation()
    print(f"Public Key (p, g, y): ({p}, {g}, {y})")
    print(f"Private Key (x): {x}")

    message = int(input("Enter the message to encrypt (as an integer < p): "))

    ciphertext = encrypt(message, p, g, y)
    print(f"Encrypted Message (c1, c2): {ciphertext}")

    decrypted_message = decrypt(ciphertext, p, x)
    print(f"Decrypted Message: {decrypted_message}")