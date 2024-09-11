
# Q2. Write a program to find the key value of the given cipher text:
# (JBCRCLQRWCRVNBJENBWRWN)

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
        else:
            # Non-alphabet characters are not shifted
            p.append(i)
    return ''.join(p)

# plainText = input("\nEnter plaintext: ")
cipherText = "JBCRCLQRWCRVNBJENBWRWN"
key = [i for i in range(0, 26)]

for k in key:
    print(f"For key = {k}")
    plainText = shift_dechiper(cipherText, k)

    print(f"PlainText: {plainText}\n")