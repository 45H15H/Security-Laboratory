def apply_func(r):
    ans = ''
    for i in range(0, len(r), 3):
        ch = r[i + 2]
        temp = r[i:i + 3]
        temp = ch + temp[:-1]
        ans += temp
    return ans

def feistel_encrypt(plain_text, rounds):
    l = len(plain_text)
    left, right = plain_text[:l // 2], plain_text[l // 2:]

    for _ in range(rounds):
        new_r = apply_func(right)
        after_xor = ''.join('0' if left[j] == new_r[j] else '1' for j in range(len(new_r)))
        left, right = right, after_xor

    return left + right

def feistel_decrypt(cipher_text, rounds):
    l = len(cipher_text)
    left, right = cipher_text[:l // 2], cipher_text[l // 2:]

    for _ in range(rounds):
        new_l = apply_func(left)
        after_xor = ''.join('0' if right[j] == new_l[j] else '1' for j in range(len(new_l)))
        right, left = left, after_xor

    return left + right

# Example usage
plain_text = input("Enter plain text: ")
rounds = int(input("Enter the number of rounds: "))

# Encrypt
cipher_text = feistel_encrypt(plain_text, rounds)
print(f'Encrypted Text: {cipher_text}')

# Decrypt
decrypted_text = feistel_decrypt(cipher_text, rounds)
print(f'Decrypted Text: {decrypted_text}')
