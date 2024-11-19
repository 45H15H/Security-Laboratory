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
int main()
{
	int a,n,k;
	cout<<"Enter the base value : "<<endl;
	cin>>a;
	cout<<"Enter the exponent value : "<<endl;
	cin>>k;
	cout<<"Enter the value of n : "<<endl;
	cin>>n;
	int c = k;
	vector<int> binary;
	while(c>0)
	{
		int temp = c%2;
		binary.push_back(temp);
		c = c/2;
		
	}
	int size = binary.size();	
	for(int i=0;i<size;i++)
	{
		cout<<binary[i];
	}
	
	int A,b,K;
	
	A = a;
	b = 1;
	K = 0;
	
	for(int i=1;i<=size;i++)
	{
		K = binary[i];
		A = (A*A)%n;
		if(K == 1)
		{
			b = (A*b) % n;
		}
	}
	cout<<endl<<"Ans = "<<b;
}