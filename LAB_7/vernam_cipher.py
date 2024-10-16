
# Q3. Write a program to encrypt and decrypt the text using vernam cipher.

def vernam_encrypt(plain_text, key):
    # Encryption
    encrypted_text = ''
    for i in range(len(plain_text)):
        x1 = ord(plain_text[i]) - ord('A')
        x2 = ord(key[i]) - ord('A')
        x = x1 ^ x2
        x = x % 26
        encrypted_text += chr(x + ord('A'))
    
    return encrypted_text

def vernam_decrypt(encrypted_text, key):
    # Decryption
    decrypted_text = ''
    for i in range(len(encrypted_text)):
        x1 = ord(encrypted_text[i]) - ord('A')
        x2 = ord(key[i]) - ord('A')
        x = x1 ^ x2
        x = x % 26
        decrypted_text += chr(x + ord('A'))
    
    return decrypted_text

# Example usage
plain_text = input("Enter the plain text (uppercase, no spaces): ").upper()
key = input("Enter the key (uppercase, same length as plain text): ").upper()

if len(plain_text) != len(key):
    print("Key must be the same length as the plain text.")
else:
    # Encrypt the plain text
    encrypted_text = vernam_encrypt(plain_text, key)
    print(f"Encrypted Text: {encrypted_text}")

    # Decrypt the cipher text
    decrypted_text = vernam_decrypt(encrypted_text, key)
    print(f"Decrypted Text: {decrypted_text}")
