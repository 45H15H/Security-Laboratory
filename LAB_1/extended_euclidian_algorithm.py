
# Q2: Write a program to find the GCD of two large integer using Extended Euclidian Algorithm.

def extended_euclidian_algorithm(a, b):
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
    r1_coeff = t2
    r2_coeff = s2
    return r2, r1_coeff, r2_coeff

a = int(input("Enter a: "))
b = int(input("Enter b: "))

print(f"""\nThe greatest common divisor of {a} and {b} is {extended_euclidian_algorithm(a, b)[0]}.
The coefficients of a and b are {extended_euclidian_algorithm(a, b)[1]} and {extended_euclidian_algorithm(a, b)[2]} respectively.
The GCD can be represented as {extended_euclidian_algorithm(a, b)[1]}*{a} + {extended_euclidian_algorithm(a, b)[2]}*{b}.\n""")
