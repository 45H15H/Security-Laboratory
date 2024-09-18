
# 21CSE1003
# Ashish Singh

# Q1. Write a program to encrypt and decrypt the message "Meet Me at the Bridge" using 
# Play fair cipher where key is "Your Name".

import numpy as np

def index_2d(myList, v):
    for i, x in enumerate(myList):
        if v in x:
            return (i, x.index(v))


def play_fair_encryption(key, plaintext):
    # matrix
    l = []
    for char in key:
        if char not in l and (char != 'i' and char != 'j'):
            l.append(char)
        elif 'i/j' not in l and (char == 'i' or char == 'j'):
            l.append('i/j')
    for _ in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i/j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']:
        if _ not in l:
            l.append(_)
    try:
        matrix = np.array(l).reshape(5, 5)
    except:
        print("More than 25 characters!!!")
    
    print(f"\nMatrix:\n{matrix}")
    matrix = matrix.tolist()
    
    # digraph
    for s in range(0,len(plaintext)+1,2):
        if s < len(plaintext)-1:
            if plaintext[s] == plaintext[s+1]:
                plaintext = plaintext[:s+1] + 'x' + plaintext[s+1:]
    if len(plaintext) % 2 != 0:
        plaintext = plaintext[:] + 'x'
    
    print(f"\nNew plaintext: {plaintext}")
    
    plaintext = [i for i in plaintext]
    while 'i' in plaintext:
        index_of_i = plaintext.index('i')
        plaintext[index_of_i] = 'i/j'
    
    ciphertext = []

    for x in range(0, len(plaintext), 2):
        c1 = plaintext[x]
        c2 = plaintext[x+1]
        a, b = index_2d(matrix, c1)
        c, d = index_2d(matrix, c2)

        if a == c:
            ciphertext.append(matrix[a][(b + 1) % 5])
            ciphertext.append(matrix[c][(d + 1) % 5])
        elif b == d:
            ciphertext.append(matrix[(a + 1) % 5 ][b])
            ciphertext.append(matrix[(c + 1) % 5 ][d])
        
        elif a != c or b != d:
            ciphertext.append(matrix[a][d])
            ciphertext.append(matrix[c][b])

    ciphertext = [i for i in ciphertext]
    while 'i/j' in ciphertext:
        index_of_i = ciphertext.index('i/j')
        ciphertext[index_of_i] = 'i'
    
    return ''.join(ciphertext)

def play_fair_decryption(key, ciphertext):
    # matrix
    l = []
    for char in key:
        if char not in l and (char != 'i' and char != 'j'):
            l.append(char)
        elif 'i/j' not in l and (char == 'i' or char == 'j'):
            l.append('i/j')
    for _ in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i/j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']:
        if _ not in l:
            l.append(_)
    try:
        matrix = np.array(l).reshape(5, 5)
    except:
        print("More than 25 characters!!!")
    
    matrix = matrix.tolist()
    
    # digraph
    for s in range(0,len(ciphertext)+1,2):
        if s < len(ciphertext)-1:
            if ciphertext[s] == ciphertext[s+1]:
                ciphertext = ciphertext[:s+1] + 'x' + ciphertext[s+1:]
    if len(ciphertext) % 2 != 0:
        ciphertext = ciphertext[:] + 'x'
    
    print(f"\nNew ciphertext: {ciphertext}")
    
    ciphertext = [i for i in ciphertext]
    while 'i' in ciphertext:
        index_of_i = ciphertext.index('i')
        ciphertext[index_of_i] = 'i/j'
    
    plaintext = []

    for x in range(0, len(ciphertext), 2):
        c1 = ciphertext[x]
        c2 = ciphertext[x+1]
        a, b = index_2d(matrix, c1)
        c, d = index_2d(matrix, c2)

        if a == c:
            plaintext.append(matrix[a][(b - 1) % 5])
            plaintext.append(matrix[c][(d - 1) % 5])
        elif b == d:
            plaintext.append(matrix[(a - 1) % 5 ][b])
            plaintext.append(matrix[(c - 1) % 5 ][d])
        
        elif a != c or b != d:
            plaintext.append(matrix[a][d])
            plaintext.append(matrix[c][b])

    plaintext = [i for i in plaintext]
    while 'i/j' in plaintext:
        index_of_i = plaintext.index('i/j')
        plaintext[index_of_i] = 'i'
    
    return ''.join(plaintext)

k = [i for i in input("\nEnter key: ")]

p = input("Enter plaintext: ")

ciphertext = play_fair_encryption(k, p)
print(f"\nCiphertext: {ciphertext}\n")
print(f"\nPlaintext: {play_fair_decryption(k, ciphertext)}\n")
