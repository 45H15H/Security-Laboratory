#include<bits/stdc++.h>
using namespace std;
vector<int> get_prime_field(int n){
    
    vector<bool> prime(n+1, true);

    for(int i=2; i*i <= n; i++){

        if(prime[i] == true){
            for(int j = i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }

    vector<int> primes;
    // cout<<"Prime Field: ";
    for(int i=2;i<=n;i++){
        if(prime[i] == true){
            // cout<<i<<" ";
            primes.push_back(i);
        }
    }

    return primes;
}
vector<int> get_extension_field(int n, vector<int> primes){
    vector<int> extension_field;
    for(int i = 0; i < primes.size(); i++) {
        int x = primes[i];
        int p = x * x;
        while(p < n) {
            extension_field.push_back(p);
            p *= x;
        }
    }

    // cout<<"Extension Field: ";
    // for(int i = 0; i < extension_field.size(); i++) {
    //     cout << extension_field[i] << " ";
    // }
    return extension_field;

}
int main()
{
    int n;
    cout<<"Enter the range: "<<endl;
    cin>>n;
    vector<int> prime_field = get_prime_field(n);
    cout<<endl;
    vector<int> extension_field = get_extension_field(n, prime_field);
    
    vector<int> field;

    for(int i=0;i<prime_field.size();i++){
        field.push_back(prime_field[i]);
    }

    for(int i=0;i<extension_field.size();i++){
        field.push_back(extension_field[i]);
    }

    sort(field.begin(),field.end());
    cout<<"Fields: "<<endl;
    for(int i=0;i<field.size();i++){
        cout<<field[i]<<" ";
    }
}