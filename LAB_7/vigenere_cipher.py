
# Q3. Write a program to encrypt and decrypt the text using vigenere

def vigenere_encrypt(plain_text, key):
    cipher_text = []
    key_length = len(key)
    
    # Extend the key to match the length of the plain text
    key = (key * (len(plain_text) // key_length)) + key[:len(plain_text) % key_length]
    
    for i in range(len(plain_text)):
        if plain_text[i].isalpha():
            shift = ord(key[i].upper()) - ord('A')
            encrypted_char = chr((ord(plain_text[i].upper()) - ord('A') + shift) % 26 + ord('A'))
            cipher_text.append(encrypted_char)
        else:
            cipher_text.append(plain_text[i])  # Non-alphabetic characters remain unchanged
            
    return ''.join(cipher_text)

def vigenere_decrypt(cipher_text, key):
    plain_text = []
    key_length = len(key)

    # Extend the key to match the length of the cipher text
    key = (key * (len(cipher_text) // key_length)) + key[:len(cipher_text) % key_length]
    
    for i in range(len(cipher_text)):
        if cipher_text[i].isalpha():
            shift = ord(key[i].upper()) - ord('A')
            decrypted_char = chr((ord(cipher_text[i].upper()) - ord('A') - shift + 26) % 26 + ord('A'))
            plain_text.append(decrypted_char)
        else:
            plain_text.append(cipher_text[i])  # Non-alphabetic characters remain unchanged
            
    return ''.join(plain_text)

# Example usage for Vigenère Cipher
plain_text_vigenere = input("Enter the plain text for Vigenère Cipher: ").replace(" ", "")
key_vigenere = input("Enter the key for Vigenère Cipher: ")

# Encrypt the plain text
encrypted_text_vigenere = vigenere_encrypt(plain_text_vigenere, key_vigenere)
print(f"Vigenère Encrypted Text: {encrypted_text_vigenere}")

# Decrypt the cipher text
decrypted_text_vigenere = vigenere_decrypt(encrypted_text_vigenere, key_vigenere)
print(f"Vigenère Decrypted Text: {decrypted_text_vigenere}")
