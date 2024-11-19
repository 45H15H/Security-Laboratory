#include<bits/stdc++.h>
using namespace std;
int find_MI(int x1, int x2){

    bool x = false;
        int c = 1;
        while(x != true){
            if((x1*c)%x2 == 1){   
                x = true;
            }else{
                c++;
            }
        }
    return c;
}
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
    // Key Generation
    int p,q;
    cout<<"Enter the values of p and q"<<endl;
    cin>>p>>q;
    int n = p*q;

    int phi_n = (p-1)*(q-1);

    int e;
    cout<<"Choose an integer e that lies between 1 and "<<n<<" and gcd of e and "<<phi_n<<" should be 1"<<endl;
    cin>>e;

    int d = find_MI(5,192);

    cout<<"The public key is ("<<n<<","<<e<<")"<<endl;
    cout<<"The private key is ("<<d<<","<<p<<","<<q<<","<<phi_n<<")"<<endl;

    // Encryption
    string message;
    cout<<"Enter the Message: "<<endl;
    cin>>message;

    string message_int;
    for(int i=0;i<message.size();i++){
        char ch = message[i];
        int val = int(ch)-64;
        string s = to_string(val);
        message_int += s;
    }

    int mess_in_int = stoi(message_int);
    cout<<mess_in_int<<endl;

    int cipher_text = easy_mod(mess_in_int,e,n);
    int decrypted_text = easy_mod(cipher_text,d,n);

    cout<<"Cipher Text: "<<cipher_text<<endl;
    cout<<"Decrypted Text: "<<decrypted_text<<endl;

    
    
}