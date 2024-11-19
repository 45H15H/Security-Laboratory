#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter an element: " << endl;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 0) {
            continue; 
        }

        vector<int> vec;
        for (int j = 0; j < n - 1; j++) {
            int x = pow(i, j);  
            int y = x % n;      
            vec.push_back(y);
        }

        sort(vec.begin(), vec.end());

        bool flag = false;
        for (int k = 1; k < vec.size(); k++) {
            if (vec[k - 1] == vec[k]) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << "Primitive Root for n = " << n << " is " << i << endl;
            return 0; 
        }
    }

}
