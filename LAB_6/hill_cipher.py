
# Q2. Write a program to encrypt and decrypt the message "Pay more money" using 
# trigraph Hill Cipher where key is "GYBNQKURP".

import numpy as np

def letter_to_number(letter):
    return ord(letter.upper()) - ord('A')

def number_to_letter(number):
    return chr((number % 26) + ord('A'))

def create_key_matrix(key):
    key = key.upper()
    key_matrix = []
    for letter in key:
        key_matrix.append(letter_to_number(letter))
    return np.array(key_matrix).reshape(3, 3)

def encrypt(message, key_matrix):
    message = message.replace(" ", "").upper()
    while len(message) % 3 != 0:
        message += 'X'
    
    encrypted_message = ''
    for i in range(0, len(message), 3):
        block = message[i:i+3]
        message_vector = np.array([letter_to_number(letter) for letter in block]).reshape(3, 1)
        encrypted_vector = np.dot(key_matrix, message_vector) % 26
        encrypted_block = ''.join([number_to_letter(num) for num in encrypted_vector.flatten()])
        encrypted_message += encrypted_block
    return encrypted_message

def mod_inverse(matrix, modulus):
    det = int(np.round(np.linalg.det(matrix)))
    det_inv = pow(det, -1, modulus)
    matrix_mod_inv = det_inv * np.round(det * np.linalg.inv(matrix)).astype(int) % modulus
    return matrix_mod_inv

def decrypt(encrypted_message, key_matrix):
    key_matrix_inv = mod_inverse(key_matrix, 26)
    
    decrypted_message = ''
    for i in range(0, len(encrypted_message), 3):
        block = encrypted_message[i:i+3]
        encrypted_vector = np.array([letter_to_number(letter) for letter in block]).reshape(3, 1)
        decrypted_vector = np.dot(key_matrix_inv, encrypted_vector) % 26
        decrypted_block = ''.join([number_to_letter(num) for num in decrypted_vector.flatten()])
        decrypted_message += decrypted_block
    return decrypted_message

key = "GYBNQKURP"
message = "PAY MORE MONEY"

key_matrix = create_key_matrix(key)

encrypted_message = encrypt(message, key_matrix)
print(f"Encrypted message: {encrypted_message}")

decrypted_message = decrypt(encrypted_message, key_matrix)
print(f"Decrypted message: {decrypted_message}")
