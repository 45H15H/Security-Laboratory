# Q2. Write a program to find the list of prime field and extension field 
# in the range of 2 to 200.

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
    return primes, powers_of_primes - primes # extension fields is power of primes but not actual primes

x, y = 2, 100

p, q = prime_powers(x, y)

print(f"Prime fields: {p}.")
print(f"Extension fields: {q}")
