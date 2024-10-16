# Q1. Write the Encryption and decryption procedure for Route cipher

import string

# Function to generate grid and fill with plain text or padding
def create_grid(plain_text, row, col):
    grid = [[''] * col for _ in range(row)]

    p, q = 0, 0
    h = 0
    index = 0

    for i in range(row * col):
        if p == row:
            q += 1
            p = 0

        if index >= len(plain_text):
            grid[p][q] = chr(65 + h)  # Padding with 'A', 'B', 'C', ...
            h += 1
        else:
            grid[p][q] = plain_text[index]
            index += 1

        p += 1

    return grid

# Function to display the grid (for debugging/visualization)
def display_grid(grid):
    for row in grid:
        print(' '.join(row))
    print()

# Function to encrypt text using the route cipher (spiral inward)
def encrypt_route_cipher(plain_text, row, col):
    grid = create_grid(plain_text, row, col)

    # Display the filled grid
    print("Grid:")
    display_grid(grid)

    # Spiral reading from the grid
    encrypted_text = ''
    up, down = 0, row - 1
    left, right = 0, col - 1

    while up <= down and left <= right:
        # Traverse down the right side
        for i in range(up, down + 1):
            encrypted_text += grid[i][right]
        right -= 1

        # Traverse left on the bottom side
        for i in range(right, left - 1, -1):
            encrypted_text += grid[down][i]
        down -= 1

        # Traverse up the left side
        if left <= right:
            for i in range(down, up - 1, -1):
                encrypted_text += grid[i][left]
            left += 1

        # Traverse right on the top side
        if up <= down:
            for i in range(left, right + 1):
                encrypted_text += grid[up][i]
            up += 1

    return encrypted_text

# Function to decrypt text using the route cipher (spiral inward)
def decrypt_route_cipher(encrypted_text, row, col):
    # Create an empty grid
    grid = [[''] * col for _ in range(row)]

    # Define the boundaries
    up, down = 0, row - 1
    left, right = 0, col - 1

    index = 0

    # Fill the grid with the cipher text in spiral order
    while up <= down and left <= right:
        # Traverse down the right side
        for i in range(up, down + 1):
            grid[i][right] = encrypted_text[index]
            index += 1
        right -= 1

        # Traverse left on the bottom side
        for i in range(right, left - 1, -1):
            grid[down][i] = encrypted_text[index]
            index += 1
        down -= 1

        # Traverse up the left side
        if left <= right:
            for i in range(down, up - 1, -1):
                grid[i][left] = encrypted_text[index]
                index += 1
            left += 1

        # Traverse right on the top side
        if up <= down:
            for i in range(left, right + 1):
                grid[up][i] = encrypted_text[index]
                index += 1
            up += 1

    # Now read the grid column by column to get the original plaintext
    decrypted_text = ''
    for p in range(col):
        for q in range(row):
            decrypted_text += grid[q][p]

    return decrypted_text.strip()

# Example usage
plain_text = input("Enter the plain text: ").replace(" ", "")
row = int(input("Enter number of rows: "))
col = int(input("Enter number of columns: "))

# Encrypt the plain text
encrypted_text = encrypt_route_cipher(plain_text, row, col)
print(f"Encrypted Text: {encrypted_text}")

# Decrypt the cipher text
decrypted_text = decrypt_route_cipher(encrypted_text, row, col)
print(f"Decrypted Text: {decrypted_text}")
