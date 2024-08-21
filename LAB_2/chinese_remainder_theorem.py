
# 21CSE1003
# Ashish Singh
# LAB 2

# Q1. Write a program to Implement Chinese Reminder Algorithm.

from math import gcd

def coprime(l: list):
    for i in range(0, len(l)):
        for j in range(i+1, len(l)):
            if gcd(l[i], l[j]) != 1:
                return False
    return True

def chinese_remainder(a: list, m: list):
    if coprime(m) == False:
        print("\nError: The moduli must be pairwise coprime.")
        return
    M = 1
    for i in m:
        M *= i
    Mi = []
    for i in m:
        Mi.append(M//i)
    yi = [] # this is Mi inverse
    for i in range(0, len(m)):
        yi.append(pow(Mi[i], -1, m[i]))
    x = 0
    for i in range(0, len(m)):
        x += a[i]*Mi[i]*yi[i]
    x = x % M
    print(f"\nThe solution is x = {x}\n")

n = int(input("\nEnter the number of equations: "))
a = []
m = []
for i in range(0, n):
    a.append(int(input(f"Enter a{i+1}: ")))
    m.append(int(input(f"Enter m{i+1}: ")))

chinese_remainder(a, m)
