#include<bits/stdc++.h>
using namespace std;
void bin(unsigned n, vector<int> &vec){
    if (n > 1)
        bin(n / 2, vec);
    int x = n % 2;
    vec.push_back(x);
}
int easy_mod(int a, int e, int n){
    vector<int> bin_repr;
    bin(e,bin_repr);
    reverse(bin_repr.begin(),bin_repr.end());
    // for(int i=0;i<bin_repr.size();i++){
    //     cout<<bin_repr[i]<<" ";
    // }

    int A = a;
    int b;
    if(bin_repr[0] == 1){
        b = A;
    }else{
        b = 1;
    }

    for(int i=1;i<bin_repr.size();i++){
        A = (A*A)%n;
        if(bin_repr[i] == 1){
            b = (A*b)%n;
        }
    }
    
    // cout<<b;
    return b;
}
int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    // Return gcd of a and b 
    return result; 
}
int main()
{
    int n;
    cout<<"Enter a number: "<<endl;
    cin>>n;

    vector<int> zn_star;

    for(int i=1;i<=n-1;i++){
        if(gcd(i,n) == 1){
            zn_star.push_back(i);
        }
    }

    int phi = zn_star.size();
    // cout<<phi;

    vector<int> factors;
    for(int i=1;i<=phi;i++){
        if(phi%i == 0){
            factors.push_back(i);
            // cout<<i<<" ";
        }
    }

    unordered_map<int, vector<int>> order;
    for(int i=0;i<zn_star.size();i++){
        for(int j=0;j<factors.size();j++){
            int x = zn_star[i];
            int y = factors[j];

            int val = easy_mod(x,y,n);

            if(val == 1){
                order[y].push_back(x);
                // cout<< x <<" "<< y<<endl;
                break;
            }
        }
    }

    
    cout<< "Generators are: ";
    for(auto j : order[phi]){
        cout<< j<< " ";
    }

    cout<<endl;
}