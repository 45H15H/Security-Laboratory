
# Q3. Write a program to find the primitive root of GF(n) where n is 
# a prime number of powers 1.

n = int(input("Enter prime number: "))

s = [i for i in range(1, n)]

primitive_root_found = False

for j in range(1, n):
    a = s.copy()
    if j % 2 == 0:
        continue
    else:
        m = 0
        while (j ** m) % n in a and len(a) >= 0:
            a.remove((j ** m) % n)
            m += 1
    if len(a) == 0:
        print(f"Primitive root of GF({n}) is: {j}")
        primitive_root_found = True
        break

if not primitive_root_found:
    print("Primitive root does not exist")
