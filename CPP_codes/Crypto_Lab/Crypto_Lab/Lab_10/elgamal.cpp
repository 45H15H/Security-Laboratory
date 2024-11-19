#include<bits/stdc++.h>
using namespace std;
// Function to perform modular exponentiation: (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// ElGamal Key Generation
void keyGeneration(long long &p, long long &g, long long &y, long long &x) {
    
    p = 11;
    g = 2; 
    x = 3; 

    y = modExp(g, x, p);
}

// ElGamal Encryption
pair<long long, long long> encrypt(long long m, long long p, long long g, long long y) {
    long long k = 4; 
    long long c1 = modExp(g, k, p);
    long long c2 = (m * modExp(y, k, p)) % p;

    return make_pair(c1, c2); 
}

// ElGamal Decryption
long long decrypt(pair<long long, long long> ciphertext, long long p, long long x) {
    long long c1 = ciphertext.first;
    long long c2 = ciphertext.second;


    long long s = modExp(c1, x, p);

    long long s_inv = modExp(s, p - 2, p); 

    long long m = (c2 * s_inv) % p;

    return m;
}

int main() {
    long long p, g, y, x;
    keyGeneration(p, g, y, x);

    cout << "Public Key (p, g, y): (" << p << ", " << g << ", " << y << ")" << endl;
    cout << "Private Key (x): " << x << endl;

    long long message;
    cout << "Enter the message to encrypt (as an integer < p): ";
    cin >> message;

    auto ciphertext = encrypt(message, p, g, y);
    cout << "Encrypted Message (c1, c2): (" << ciphertext.first << ", " << ciphertext.second << ")" << endl;

    long long decryptedMessage = decrypt(ciphertext, p, x);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}

