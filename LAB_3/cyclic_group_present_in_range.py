
# Q2. Write a program to find the list of cyclic group present within a range (Example: 2000 to 3000).

from math import gcd

def is_primitive_root(g, n):
    required_set = set(num for num in range(1, n) if gcd(num, n) == 1)
    actual_set = set(pow(g, powers, n) for powers in range(1, n))
    return required_set == actual_set

def find_cyclic_groups(start, end):
    cyclic_groups = []
    
    for n in range(start, end + 1):
        if n == 1:  # The group Z1 is trivial and not considered cyclic
            continue
        if any(is_primitive_root(g, n) for g in range(1, n)):
            cyclic_groups.append(n)
    
    return cyclic_groups

start = 200
end = 300
cyclic_groups = find_cyclic_groups(start, end)
print(cyclic_groups)
