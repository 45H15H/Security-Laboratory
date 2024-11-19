#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2;
    cout<<"Enter the 2 numbers: "<<endl;
    cin>>x1>>x2;

    int a,b;
    // a is the largest number out of the two
    if(x1>x2){
        a = x1;
        b = x2;
    }else{
        a = x2;
        b = x1;
    }

    int r = a%b;
    int q = a/b;
    while(r!=0){
        a = b;
        b = r;
        q = a/b;
        r = a%b;
    }

    cout<<"GCD of the numbers is: "<<b<<endl;

    
}