
# Q4. Perform addition and multiplication operation on GF(16) and finds additive
# and multiplicative inverse of each element present in GF(16).

# for GF(16)

print("\n")
print("+", end = "  ")
for i in range(4):
    print(bin(i)[2:].zfill(2), end = " ")
print()

for i in range(4):
    print(bin(i)[2:].zfill(2), end = " ")
    for j in range(4):
        print(bin(i ^ j)[2:].zfill(2), end = " ")
    print()

print("\n")

for i in range(4):
    for j in range(4):
        if i ^ j == 0:
            print(f"Additive inverse of {bin(i)[2:].zfill(2)} is {bin(j)[2:].zfill(2)}")



print("\n")