
# Q4. Write a program to find the quadratic residue and quadratic nonresidue mod n where n is a large integer.

from math import gcd

def Zn_star(n):
    Zn = [i for i in range(n)]

    Zn_ = [] # this is Zn*
    for i in Zn:
        if gcd(i, n) == 1:
            Zn_.append(i)
    print(f"Zn* = {Zn_}")

    return Zn_


def Qn_Qn_bar(n):
    Zn_ = Zn_star(n)
    Qn = []
    for i in Zn_:
        Qn.append(i**2 % n)
    Qn = set(Qn)
    Zn_ = set(Zn_)
    Qn_bar = Zn_ - Qn
    print(f"Qn = {Qn}")
    print(f"Qn_bar = {Qn_bar}")

n = int(input("\nEnter value of n: "))

Qn_Qn_bar(n)