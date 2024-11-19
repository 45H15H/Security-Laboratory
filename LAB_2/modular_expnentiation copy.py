
# Q3. Write a program to implement Modular exponentiation using repeated square and multiply algorithm.

def modular_exponentiation(a, e, n):
    k = bin(e)[2:]
    b = 1
    new_e = k[0]

    if k[0] == "1":
        b = a
    

a = int(input("Enter a:"))
e = int(input("Enter e:"))
n = int(input("Enter n:"))

print(f"{a}^{e} mod {n}")


