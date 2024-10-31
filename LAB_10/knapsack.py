def mod_inverse(w, M):
    m0, y, x = M, 0, 1
    while w > 1:
        q, w, M = w // M, M, w % M
        y, x = x - q * y, y
    return x + m0 if x < 0 else x

# Get inputs
pt = input("Enter the binary message: ")
grps = int(input("Enter the number of groups in knapsack: "))
private_key = [int(input(f"Enter private key value {i + 1}: ")) for i in range(grps)]
M, w = map(int, input("Enter M and w (coprime) separated by space: ").split())

# Generate public key
public_key = [(pk * w) % M for pk in private_key]

# Encrypt message
cipher_text = []
for i in range(0, len(pt), grps):
    group = pt[i:i + grps].ljust(grps, '0')  # Pad if the last group is shorter
    sum_encryption = sum(public_key[j] for j, bit in enumerate(group) if bit == '1')
    cipher_text.append(sum_encryption)
print("Encrypted Message:", cipher_text)

# Decrypt message
w_inverse = mod_inverse(w, M)
decrypted_message = ''
for c in cipher_text:
    sum_decryption = (c * w_inverse) % M
    group_bits = []
    for k in reversed(private_key):
        if sum_decryption >= k:
            sum_decryption -= k
            group_bits.append('1')
        else:
            group_bits.append('0')
    decrypted_message += ''.join(reversed(group_bits))

print("Decrypted Message:", decrypted_message)
