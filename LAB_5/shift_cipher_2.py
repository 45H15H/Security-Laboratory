# Q1. Write a program to encrypt the message "i transfered rs 2034 to you" using shift cipher
# with any key value. Then decrypt the message back to plain text.

def shift_cipher(plainText, key):
    c = []
    for i in plainText:
        if i.isalpha():  # Only shift alphabetic characters
            # For lowercase letters
            if i.islower():
                shifted_char = chr((ord(i) - ord('a') + key) % 26 + ord('a'))
            # For uppercase letters
            elif i.isupper():
                shifted_char = chr((ord(i) - ord('A') + key) % 26 + ord('A'))
            c.append(shifted_char)
        elif i.isdigit():
            shifted_char = chr((ord(i) - ord('0') + key) % 10 + ord('0'))
            c.append(shifted_char)
        else:
            # Non-alphabet characters are not shifted
            c.append(i)
    return ''.join(c)

def shift_dechiper(chipherText, key):
    p = []
    for i in chipherText:
        if i.isalpha():  # Only shift alphabetic characters
            # For lowercase letters
            if i.islower():
                shifted_char = chr((ord(i) - ord('a') - key) % 26 + ord('a'))
            # For uppercase letters
            elif i.isupper():
                shifted_char = chr((ord(i) - ord('A') - key) % 26 + ord('A'))
            p.append(shifted_char)
        elif i.isdigit():
            shifted_char = chr((ord(i) - ord('0') - key) % 10 + ord('0'))
            p.append(shifted_char)
        else:
            # Non-alphabet characters are not shifted
            p.append(i)
    return ''.join(p)

plainText = "i transfered rs 2034 to you"
key = int(input("\nEnter key: "))

cipherText = shift_cipher(plainText, key)
plainText_2 = shift_dechiper(cipherText, key)

print(f"\nCipherText: {cipherText}")
print(f"PlainText: {plainText_2}\n")