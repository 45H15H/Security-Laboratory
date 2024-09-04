
# 21CSE1003
# Ashish Singh

# Q1. Write a program to find the list of generators present in Zn* where n is a large integer.

from math import gcd

def find_generators(n):
  generators = []
  
  zn_star = [x for x in range(1, n) if gcd(x, n) == 1]

  for g in zn_star:
    powers = [g]
    while powers[-1] != 1:
      powers.append((powers[-1] * g) % n)
    if len(powers) == len(zn_star):
      generators.append(g)

  return generators

n = int(input("Enter n: "))
generators = find_generators(n)
print("Generators of Zn* for n =", n, ":", generators)