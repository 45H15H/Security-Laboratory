
# Q3. Write a program to find Multiplicative Inverse of a inputted number using Extended Euclidian Algorithm.

def multiplicative_inverse_eea(a, b):
    if a >= b:
        r1, r2 = a, b
    else:
        r1, r2 = b, a
    t1, t2 = 1, 0
    s1, s2 = 0, 1
    q = r1 // r2
    r = r1 % r2
    t = t1 - q * t2
    s = s1 - q * s2
    while r != 0:
        r1 = r2
        r2 = r
        t1 = t2
        t2 = t
        s1 = s2
        s2 = s
        q = r1 // r2
        r = r1 % r2
        t = t1 - q * t2
        s = s1 - q * s2
    return s2 if s2 > 0 else s2 + b

a = int(input("Enter a: "))
b = int(input("Enter b: "))



print(f"""\nMultiplicative Inverse of {a} in Z{b} is {multiplicative_inverse_eea(a, b)}.""")
