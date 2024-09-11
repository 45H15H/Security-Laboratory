
# Ashish Singh
# 21CSE1003

# Q1. Write a program to list all Zn which is a field under addition and multiplication 
# in the range of 2 to 100.



def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def prime_powers(a, b):
    primes = set()
    powers_of_primes = set()
    for num in range(a, b + 1):
        if is_prime(num):
            primes.add(num)
            power = num
            while power <= b:
                powers_of_primes.add(power)
                power *= num
    return primes | powers_of_primes

x, y = 2, 100

p = prime_powers(x, y)

print(f"List of Zn which is field: {p}.")
