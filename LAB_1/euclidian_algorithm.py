
# 21CSE1003
# Ashish Singh
# LAB 1

#---------------------------------------------------------------------------------------

# Q1: Write a program to find the GCD of two large integer using Euclidian Algorithm.

def euclidian_algorithm(a, b):
    r = a % b
    while r != 0:
        a = b
        b = r
        r = a % b
    return b

a = int(input("Enter a: "))
b = int(input("Enter b: "))

print(f"\nThe greatest common divisor of {a} and {b} is {euclidian_algorithm(a, b)}.\n")
