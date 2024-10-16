
# 21CSE1003 Ashish Singh
# Q1. Write the Encryption and decryption procedure for Column Transposition

import math, random, string

# Function to generate a random lowercase letter
def random_lowercase():
    return random.choice(string.ascii_lowercase)

# Function to convert the key from text to numerical order
def convert_key_to_numeric(key):
    sorted_key = sorted(key)
    key_order = {char: str(sorted_key.index(char) + 1) for char in key}
    return ''.join(key_order[char] for char in key)

# Encryption function
def encrypt_columnar_transposition(plain_text, key):
    # Convert the key to numeric order
    key = convert_key_to_numeric(key)
    
    # Remove spaces from the plain_text
    plain_text = plain_text.replace(" ", "")

    # Calculate number of columns and rows
    col = len(key)
    row = math.ceil(len(plain_text) / col)

    # Create a grid (matrix) to write the plain text row-wise
    grid = [[''] * col for _ in range(row)]

    index = 0
    for r in range(row):
        for c in range(col):
            if index < len(plain_text):
                grid[r][c] = plain_text[index]
                index += 1
            else:
                grid[r][c] = random_lowercase()  # Padding with random lowercase letters

    # Create a sorted key order
    sorted_key_order = sorted(list(enumerate(key)), key=lambda x: x[1])

    # Read the grid column-wise in the order specified by the sorted key
    cipher_text = ''
    for col_idx, _ in sorted_key_order:
        for r in range(row):
            cipher_text += grid[r][col_idx]

    return cipher_text

# Decryption function
def decrypt_columnar_transposition(cipher_text, key):
    # Convert the key to numeric order
    key = convert_key_to_numeric(key)
    
    # Calculate number of columns and rows
    col = len(key)
    row = math.ceil(len(cipher_text) / col)

    # Create a sorted key order to determine column positions
    sorted_key_order = sorted(list(enumerate(key)), key=lambda x: x[1])

    # Rebuild the grid with empty characters
    grid = [[''] * col for _ in range(row)]

    # Calculate how many characters in each column
    col_lengths = [row] * col
    total_chars = len(cipher_text)
    short_cols = col * row - total_chars
    for i in range(short_cols):
        col_lengths[sorted_key_order[col - 1 - i][0]] -= 1

    # Fill the grid column by column based on the key order
    index = 0
    for col_idx, _ in sorted_key_order:
        for r in range(col_lengths[col_idx]):
            if index < len(cipher_text):
                grid[r][col_idx] = cipher_text[index]
                index += 1

    # Read the grid row-wise to reconstruct the plain text
    plain_text = ''
    for r in range(row):
        for c in range(col):
            plain_text += grid[r][c]
    return plain_text

# Example usage
plain_text = "WE ARE DISCOVERED FLEES AT ONCE"
key = "ZEBRAS"
# Encrypt
cipher_text = encrypt_columnar_transposition(plain_text, key)
print(f"Ciphertext: {cipher_text}")
# Decrypt
decrypted_text = decrypt_columnar_transposition(cipher_text, key)
print(f"Decrypted Text: {decrypted_text}")