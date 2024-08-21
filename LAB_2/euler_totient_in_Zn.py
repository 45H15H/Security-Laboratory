
# Q4. Write a program to find Euler totient value in Zn.

from math import gcd

def euler_totient(n):
    Zn = [i for i in range(n)]
    print(f"Zn = {Zn}")

    Zn_ = [] # this is Zn*
    for i in Zn:
        if gcd(i, n) == 1:
            Zn_.append(i)
    print(f"Zn* = {Zn_}")

    phi = len(Zn_)
    print(f"\nphi({n}) = {phi}")

n = int(input("\nEnter value of n: "))

euler_totient(n)