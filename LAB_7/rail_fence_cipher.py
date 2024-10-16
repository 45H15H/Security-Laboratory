# Q1. Write the Encryption and decryption procedure for Rail fence cipher

def encrypt_rail_fence(plain_text, key):
    # Create a grid with '0' as placeholders
    grid = [['0' for _ in range(len(plain_text))] for _ in range(key)]
    
    # Populate the grid in the zigzag manner (like in the C++ version)
    for i, char in enumerate(plain_text):
        if (i // (key - 1)) % 2 == 0:
            row = i % (key - 1)
        else:
            row = (key - 1) - (i % (key - 1))

        grid[row][i] = char

    # Collect the encrypted text by reading row by row
    encrypted_text = ""
    for r in range(key):
        for c in range(len(plain_text)):
            if grid[r][c] != '0':
                encrypted_text += grid[r][c]
    
    return encrypted_text

# Example usage
plain_text = input("Enter the plain text: ").replace(" ", "")
key = int(input("Enter the key: "))

# Encrypt the plain text
encrypted_text = encrypt_rail_fence(plain_text, key)
print(f"Encrypted Text: {encrypted_text}")
