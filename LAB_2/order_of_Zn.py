
# Q5. Write a program to find order of modulo n in Zn.

from math import gcd

def order_of_Zn(n):
    Zn = [i for i in range(n)]
    Zn = set(Zn)
    print(f"Zn = {Zn}")

    Zn_ = set() # this is Zn*
    for i in Zn:
        if gcd(i, n) == 1:
            Zn_.add(i)
    print(f"Zn* = {Zn_}")

    phi = len(Zn_)
    print(f"\nphi({n}) = {phi}")

    t = set() # factors of phi(n)
    for x in range(1, phi+1):
        if phi % x == 0:
            t.add(x)
    print(f"\nfactors of phi({n}) = {t}")

    order = set()

    for i in Zn_:
        for j in t:
            if i**j % n == 1:
                order.add((i, j))
                break
    print(f"\norder of Zn = {order}\n")

n = int(input("\nEnter the value of n: "))
order_of_Zn(n)
