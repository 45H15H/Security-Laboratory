
# Q3. Substitution cipher implementation
def substitution(plainText, keyDict):
    c = []
    for i in plainText:
        c.append(keyDict[i])
    return ''.join(c)

d = {'A': '_',
     'B': '_',
     'C': '_',
     'D': '_',
     'E': '_',
     'F': '_',
     'G': '_',
     'H': '_',
     'I': '_',
     'J': '_',
     'K': '_',
     'L': '_',
     'M': '_',
     'N': '_',
     'O': '_',
     'P': '_',
     'Q': '_',
     'R': '_',
     'S': '_',
     'T': '_',
     'U': '_',
     'V': '_',
     'W': '_',
     'X': '_',
     'Y': '_',
     'Z': '_'}

for _ in d.keys():
    t = input(f"Enter substitution for {_}: ")
    if t in d.values():
        print("substitution already assigned")
    else:
        d[_] = t.upper()
            
print(f"\n{d}\n")

plainText = input("\nEnter plain text: ").upper()
cipherText = substitution(plainText, d)

print(f"Encrypted text: {cipherText}\n")