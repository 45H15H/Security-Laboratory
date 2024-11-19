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
bool if_cyclic(int n){
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

    vector<int> gen;
    for(auto j : order[phi]){
        gen.push_back(j);
    }

    if(gen.size()!=0){
        return true;
    }

    return false;
}
int main()
{
    vector<int> cyc;
    int start, end;
    cout<<"Enter the start value of the range: "<<endl;
    cin>>start;
    cout<<"Enter the end value of the range: "<<endl;
    cin>>end;
    for(int i=start;i<=end;i++){
        if(if_cyclic(i)){
            cyc.push_back(i);
        }
    }

    for(int i=0;i<cyc.size();i++){
        cout<<cyc[i]<<" ";
    }
}