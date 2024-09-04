
# Q5. Write a program to find the square root of a modulo n where n is a large integer.

from math import gcd

def Zn_star(n):
    Zn = [i for i in range(n)]

    Zn_ = [] # this is Zn*
    for i in Zn:
        if gcd(i, n) == 1:
            Zn_.append(i)
    return Zn_


def root_modulo_n(n, a):
    Zn_ = Zn_star(n)
    s = []
    for i in Zn_:
        if i**2 % n == a:
            s.append(i)
    print(s)


n = int(input("\nEnter value of n: "))
a = int(input("Enter value of a: "))

root_modulo_n(n, a)
