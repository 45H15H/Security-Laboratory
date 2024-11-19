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
bool find_el(vector<int> vec, int x){
    for(int i=0;i<vec.size();i++){
        if(vec[i] == x){
            return true;
        }
    }

    return false;
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

    vector<int> qn;
    for(int i=0;i<zn_star.size();i++){
        int x = (zn_star[i]*zn_star[i])%n;
        if(qn.size() == 0 || (!find_el(qn,x))){
            qn.push_back(x);
        }
    }

    for(int i=0;i<qn.size();i++){
        cout<<qn[i]<<" ";
    }
    cout<<endl;
    

    vector<int> qn_bar;
    for(int i=0;i<zn_star.size();i++){
        bool var = false;
        for(int j=0;j<qn.size();j++){
            if(zn_star[i] == qn[j]){
                var = true;               
            }
        }
        if(var == false){
            qn_bar.push_back(zn_star[i]);
        }
    }

    for(int i=0;i<qn_bar.size();i++){
        cout<<qn_bar[i]<<" ";
    }
}