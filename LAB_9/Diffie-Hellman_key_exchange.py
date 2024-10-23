
# Q2. Implement the Diffie-Hellman Key Exchange mechanism.

p = int(input("Enter the value of p: "))
g = int(input("Enter the value of g: "))

a = int(input(f"Enter a value for Alice between 0 and {p - 1}: "))
b = int(input(f"Enter b value for Bob between 0 and {p - 1}: "))

A = g ** a % p
B = g ** b % p

Ka = B ** a % p
Kb = A ** b % p

print(f"The keys are: {Ka} & {Kb}")
