#include<bits/stdc++.h>
using namespace std;
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

    // for(int i=0;i<zn_star.size();i++){
    //     cout<<zn_star[i]<<" ";
    // }

    unordered_map<int,vector<int>> square_root;
    for(int i=0;i<zn_star.size();i++){
        int x = (zn_star[i]*zn_star[i])%n;
        square_root[x].push_back(zn_star[i]);
    }

    // for(auto i:square_root){
    //     cout<<"Square root of "<<i.first<<" are: ";
    //     for(auto j:square_root[i.first]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    int a = 12;
    cout<<"Square root of "<<a<<" are: ";
    for(auto j:square_root[a]){
        cout<<j<<" ";
    }
}