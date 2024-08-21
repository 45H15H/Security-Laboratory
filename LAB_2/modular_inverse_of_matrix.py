
# Q2. Write a program to find the Modular Inverse of a 3x3 matrix using Extended Euclidian Algorithm.

import numpy as np

def determinant(matrix):
    return np.linalg.det(matrix)

def modular_inverse(m, n):
    actual_det = determinant(m)
    if determinant(m) == 0:
        print("\nDeterminant does not exist.")
        return
    if determinant(m) < 0:
        det = round(determinant(m) % n)
    else:
        det = round(determinant(m))
    
    inv = np.linalg.inv(m)
    inv = inv * actual_det
    print("\nInverse of the matrix is:")
    print(f"1/{det} *\t {inv}")
    
    c = 1 # c is mulitpicative inverse
    while (det * c) % n != 1:
        c += 1
    
    print(f"\nMultiplicative inverse of {det}^-1 is: {c}")

    print(f"\n{c} * {inv} mod {n}")
    inv = c * inv
    print(f"\n{inv} mod {n}")
    
    mod_inv = np.mod(inv, 26)

    print(f"\nModular inverse of matrix is: \n{mod_inv}")

rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))
print("Enter the matrix values separated by space followed by newline:")

matrix = np.array([input().strip().split() for _ in range(rows)], int)

n = int(input("\nEnter n: "))

modular_inverse(matrix, n)
