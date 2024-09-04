
# Q3. Write a program to find the order of an element in Zn where n is a large integer.

from math import gcd

def order_of_element(g, n):
    if gcd(g, n) != 1:
        return None  # g must be coprime with n to belong to Zn*

    k = 1
    power = g % n
    while power != 1:
        power = (power * g) % n
        k += 1

    return k

n = int(input("Enter n: "))
g = int(input("Enter g: "))
order = order_of_element(g, n)
if order:
    print(f"The order of element {g} in Z_{n}* is {order}.")
else:
    print(f"Element {g} is not in Z_{n}* (not coprime with {n}).")
