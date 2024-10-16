
# Q2. Write a program to encrypt and decrypt the text using Affine cipher.

# Function to find the modular inverse of a under modulo m
def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    raise ValueError(f"Inverse of {a} mod {m} does not exist")

# Function to encrypt using Affine Cipher
def affine_encrypt(plain_text, a, b):
    cipher_text = ""
    m = 26  # Size of the alphabet

    for char in plain_text:
        if char.isalpha():  # Encrypt only alphabetic characters
            x = ord(char.upper()) - 65
            encrypted_char = (a * x + b) % m
            cipher_text += chr(encrypted_char + 65)
        else:
            cipher_text += char  # Non-alphabetic characters remain unchanged

    return cipher_text

# Function to decrypt using Affine Cipher
def affine_decrypt(cipher_text, a, b):
    plain_text = ""
    m = 26  # Size of the alphabet
    a_inv = mod_inverse(a, m)  # Find modular inverse of 'a'

    for char in cipher_text:
        if char.isalpha():  # Decrypt only alphabetic characters
            y = ord(char.upper()) - 65
            decrypted_char = (a_inv * (y - b)) % m
            plain_text += chr(decrypted_char + 65)
        else:
            plain_text += char  # Non-alphabetic characters remain unchanged

    return plain_text

# Example usage
plain_text = input("Enter the plain text: ").replace(" ", "")
a = int(input("Enter key 'a' (must be coprime with 26): "))
b = int(input("Enter key 'b': "))

# Encrypt the plain text
encrypted_text = affine_encrypt(plain_text, a, b)
print(f"Encrypted Text: {encrypted_text}")

# Decrypt the cipher text
decrypted_text = affine_decrypt(encrypted_text, a, b)
print(f"Decrypted Text: {decrypted_text}")
