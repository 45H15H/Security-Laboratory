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
    cout<<"Enter the value Zn"<<endl;
    cin>>n;

    vector<int> z_star;
    for(int i=1;i<=n-1;i++){
        if(gcd(i,n) == 1){
            z_star.push_back(i);
        }
    }

    cout<<z_star.size()<<endl;
}