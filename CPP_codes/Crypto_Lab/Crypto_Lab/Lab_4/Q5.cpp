#include <iostream>

using namespace std;

const int irreducible_poly = 0b10000011;

int multiply_GF128(int a, int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1) {
            result ^= a;
        }
        a <<= 1;
        if (a & 0b10000000) {  // If degree is greater than or equal to 7
            a ^= irreducible_poly;
        }
        b >>= 1;
    }
    return result;
}

int multiplicative_inverse_GF128(int a) {
    if (a == 0) {
        cout << "0 has no multiplicative inverse in GF(128)." << endl;
        return -1;
    }
    for (int i = 1; i < 128; ++i) {
        if (multiply_GF128(a, i) == 1) {
            return i;
        }
    }
    cout << "No multiplicative inverse found for " << a << " in GF(128)." << endl;
    return -1;
}

int main() {
    int a = 95;
    int inverse = multiplicative_inverse_GF128(a);
    
    if (inverse != -1) {
        cout << "The multiplicative inverse of " << a << " in GF(128) is " << inverse << "." << endl;
    }

    return 0;
}
