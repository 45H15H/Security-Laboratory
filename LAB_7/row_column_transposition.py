# Q1. Write the Encryption and decryption procedure for Row column transposition


import math

# Function to create a grid for row-column transform
def create_grid(plain_text, row, col):
    grid = [[''] * col for _ in range(row)]

    index = 0
    for r in range(row):
        for c in range(col):
            if index < len(plain_text):
                grid[r][c] = plain_text[index]
                index += 1
            else:
                grid[r][c] = 'X'  # Padding with 'X' if necessary

    return grid

# Function to display the grid (for debugging/visualization)
def display_grid(grid):
    for row in grid:
        print(' '.join(row))
    print()

# Function to encrypt text using row-column transform cipher
def encrypt_row_column(plain_text, row, col):
    # Remove spaces from plain text
    plain_text = plain_text.replace(" ", "")
    
    # Create the grid
    grid = create_grid(plain_text, row, col)
    
    # Display the filled grid
    print("Grid:")
    display_grid(grid)
    
    # Read the grid column by column to generate ciphertext
    encrypted_text = ''
    for c in range(col):
        for r in range(row):
            encrypted_text += grid[r][c]

    return encrypted_text

# Function to decrypt text using row-column transform cipher
def decrypt_row_column(cipher_text, row, col):
    # Create an empty grid
    grid = [[''] * col for _ in range(row)]
    
    # Fill the grid column by column with the cipher text
    index = 0
    for c in range(col):
        for r in range(row):
            if index < len(cipher_text):
                grid[r][c] = cipher_text[index]
                index += 1

    # Display the filled grid
    print("Decryption Grid:")
    display_grid(grid)
    
    # Read the grid row by row to generate plaintext
    decrypted_text = ''
    for r in range(row):
        for c in range(col):
            decrypted_text += grid[r][c]

    return decrypted_text.strip('X')  # Remove padding 'X' characters

# Example usage
plain_text = input("Enter the plain text: ").replace(" ", "")
row = int(input("Enter number of rows: "))
col = int(input("Enter number of columns: "))

# Encrypt the plain text
encrypted_text = encrypt_row_column(plain_text, row, col)
print(f"Encrypted Text: {encrypted_text}")

# Decrypt the cipher text
decrypted_text = decrypt_row_column(encrypted_text, row, col)
print(f"Decrypted Text: {decrypted_text}")
