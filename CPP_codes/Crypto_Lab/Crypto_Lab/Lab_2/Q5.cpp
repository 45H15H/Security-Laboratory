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
    // for(int i=0;i<z_star.size();i++){
    //     cout<<z_star[i]<<" ";
    // }

    // cout<<endl;

    int phi = z_star.size();
    // cout<<phi<<endl;
    vector<int> t;
    for(int i=1;i<=phi;i++){
        if(phi%i == 0){
            // cout<<i<<" ";
            t.push_back(i);
        }
    }

    vector<int> order;
    for(int i=0;i<z_star.size();i++){
        int q1 = z_star[i];
        for(int j=0;j<t.size();j++){
            int q2 = t[j];
            long long int res = pow(q1,q2);
            if(res%n == 1){
                cout<<"Order "<<q1<<"-"<<q2<<endl;
                order.push_back(q2);
                break;
            }
        }
    }

    
    
}