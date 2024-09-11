# Q1. Write a program to encrypt the message "i transfered rs 2034 to you" using shift cipher
# with any key value. Then decrypt the message back to plain text.

Z36 = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def shift_cipher(plainText, key):
    c = []
    for i in plainText:
        if i.isalpha():  # Only shift alphabetic characters
            if i.islower():
                shifted_char = Z36[(Z36.index(i.upper()) + key) % 36]
            elif i.isupper():
                shifted_char = Z36[(Z36.index(i) + key) % 36]
            c.append(shifted_char)
        elif i.isdigit():
                shifted_char = Z36[(Z36.index(i) + key) % 36]
                c.append(shifted_char)
        else:
            c.append(i)
    return ''.join(c)

def shift_dechiper(chipherText, key):
    p = []
    for i in chipherText:
        if i.isalpha():  # Only shift alphabetic characters
            if i.islower():
                shifted_char = Z36[(Z36.index(i.upper()) - key) % 36]
            elif i.isupper():
                shifted_char = Z36[(Z36.index(i) - key) % 36]
            p.append(shifted_char)
        elif i.isdigit():
                shifted_char = Z36[(Z36.index(i) - key) % 36]
                p.append(shifted_char)
        else:
            p.append(i)
    return ''.join(p)

plainText = "i transfered rs 2034 to you"
key = int(input("\nEnter key: "))

cipherText = shift_cipher(plainText, key)
plainText_2 = shift_dechiper(cipherText, key)

print(f"\nCipherText: {cipherText}")
print(f"PlainText: {plainText_2}\n")