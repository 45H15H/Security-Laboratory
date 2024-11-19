#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of Z: "<<endl;
    cin>>n;

    cout<<"The set of Additive inverse consists of: "<<endl;
    cout<<"("<<0<<","<<0<<"),";
    for(int i=1;i<=n/2;i++){
        cout<<"("<<i<<","<<n-i<<"),";
    }
}