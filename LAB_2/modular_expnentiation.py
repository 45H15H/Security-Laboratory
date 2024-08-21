
# Q3. Write a program to implement Modular exponentiation using repeated square and multiply algorithm.

def modular_exponentiation(base, exponent, modulus):
    result = 1
    base = base % modulus

    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent = exponent // 2
        base = (base * base) % modulus

    return result

base = int(input("\nEnter the base value: "))
exponent = int(input("Enter the exponent value: "))
modulus = int(input("Enter the value of n: "))

result = modular_exponentiation(base, exponent, modulus)

print(f"Ans = {result}\n")