#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,g;
    cout<<"Enter values of p and g"<<endl;
    cin>>p>>g;

    int a,b;
    cout<<"Enter the values of a and b between 0 and "<<p-1<<endl;
    cin>>a>>b;

    int A = pow(g,a);
    A = A%p;
    int B = pow(g,b);
    B = B%p;
    
    int Key_a = pow(B,a);
    Key_a = Key_a%p;

    int Key_b = pow(A,b);
    Key_b = Key_b%p;

    cout<<"Key_a = "<<Key_a<<" and Key_b = "<<Key_b<<endl;

}   