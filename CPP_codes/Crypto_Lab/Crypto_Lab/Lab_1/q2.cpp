#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1, x2;
    cout<<"Enter 2 numbers: "<<endl;
    cin>>x1>>x2;
    int n;
    int r1,r2;
    if(x1 > x2){
        r1 = x1;
        r2 = x2;
        n = x1;
    }else{
        r1 = x2;
        r2 = x1;
        n = x2;
    }

    int q = r1/r2;
    int r = r1%r2;

    int t1 = 1;
    int t2 = 0;
    int s1 = 0;
    int s2 = 1;

    int t = (t1 - q*t2);
    int s = (s1 - q*s2);

    while(r != 0){
        r1 = r2;
        r2 = r;

        q = r1/r2;
        r = r1%r2;

        t1 = t2;
        t2 = t;
        t = (t1 - q*t2);

        s1 = s2;
        s2 = s;
        s = (s1 - q*s2);
    }

    cout<<"s2 : "<<s2<<endl;
    int p = s2>0 ? s2 : s2+n;

    cout<<"GCD: "<<r2<<endl;
    if(r2 == 1){
        cout<<"M.I: "<<p;
    }
}