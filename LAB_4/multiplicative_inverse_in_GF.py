
# Q5. Find multiplicative inverse of 95 in GF(128).

irreducible_poly = 0b10000011

def multiply_GF128(a, b):
    result = 0
    while b > 0:
        if b & 1:
            result ^= a
        a <<= 1
        if a & 0b10000000:  # If degree is greater than or equal to 7
            a ^= irreducible_poly
        b >>= 1
    return result

def multiplicative_inverse_GF128(a):
    if a == 0:
        raise ValueError("0 has no multiplicative inverse in GF(128).")
    for i in range(1, 128):
        if multiply_GF128(a, i) == 1:
            return i
    raise ValueError(f"No multiplicative inverse found for {a} in GF(128).")

a = 95
inverse = multiplicative_inverse_GF128(a)

print(f"The multiplicative inverse of {a} in GF(128) is {inverse}.")
