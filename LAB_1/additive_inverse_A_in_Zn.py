
# Q5. Write a program to find Additive Inverse of a inputted number A in Zn.

a = int(input("Enter A: "))
n = int(input("Enter n: "))

for i in range(n//2+2):
    if (a + i) % n == 0:
        inverse = i
        break

print(f"""\nAdditive inverse of {a} in Z{n} is {inverse}.""") 
