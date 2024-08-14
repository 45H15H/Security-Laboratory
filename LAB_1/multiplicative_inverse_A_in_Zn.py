
# Q4. Write a program to find Multiplicative Inverse of a inputted number A in Zn.

a = int(input("Enter A: "))
n = int(input("Enter n: "))

c = 1

while (a * c) % n != 1:
    c += 1

print(f"""\nMultiplicative inverse of {a} in Z{n} is {c}.""") 
