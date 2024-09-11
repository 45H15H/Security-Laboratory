# Q4. Perform addition and multiplication operation on GF(16) and finds additive
# and multiplicative inverse of each element present in GF(16).
# for GF(16)

irreducible_poly = 0b10011

def add_GF16(a, b):
    return a ^ b

def multiply_GF16(a, b):
    result = 0
    while b > 0:
        if b & 1:
            result ^= a
        a <<= 1
        if a & 0b10000:  # If degree is greater than or equal to 4
            a ^= irreducible_poly
        b >>= 1
    return result

def additive_inverse_GF16(a): return a

def multiplicative_inverse_GF16(a):
    if a == 0:
        raise ValueError("0 has no multiplicative inverse in GF(16).")
    for i in range(1, 16):
        if multiply_GF16(a, i) == 1:
            return i
    raise ValueError(f"No multiplicative inverse found for {a} in GF(16).")

GF16_elements = list(range(16))

print("Addition table for GF(16):")
for i in GF16_elements:
    for j in GF16_elements: print(f"{i} + {j} = {add_GF16(i, j)}")

print("\nMultiplication table for GF(16):")
for i in GF16_elements:
    for j in GF16_elements: print(f"{i} * {j} = {multiply_GF16(i, j)}")

print("\nAdditive inverses in GF(16):")
for i in GF16_elements: print(f"Additive inverse of {i} is {additive_inverse_GF16(i)}")

print("\nMultiplicative inverses in GF(16):")
for i in GF16_elements: 
    if i != 0:
        print(f"Multiplicative inverse of {i} is {multiplicative_inverse_GF16(i)}")
