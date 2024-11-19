#include<bits/stdc++.h>
using namespace std;
int modInverse(int w, int M) {
    int m0 = M, y = 0, x = 1;
    if (M == 1)
        return 0;
    
    while (w > 1) {
        int q = w / M;
        int t = M;
        

        M = w % M;
        w = t;
        t = y;
        
        
        y = x - q * y;
        x = t;
    }

    
    if (x < 0)
        x += m0;

    return x;
}
int main()
{
    string pt;
    cout<<"Enter the message: "<<endl;
    cin>>pt;

    int grps;
    cout<<"Enter the number of groups in knapsack: "<<endl;
    cin>>grps;

    vector<int> private_key;
    cout<<"Enter the private key: "<<endl;
    for(int i=0;i<grps;i++){
        int temp;
        cin>>temp;
        private_key.push_back(temp);
    }

    int M,w;
    cout<<"Enter M and w such that they are coprime: "<<endl;
    cin>>M>>w;

    vector<int> public_key;
    for(int i=0;i<grps;i++){
        int val = private_key[i]*w;
        val = val%M;
        public_key.push_back(val);
    }


    // Encyption
    vector<int> cipher_text;
    for(int i=0;i<pt.length();i+=grps){
        string temp = pt.substr(i,grps);
        int sum = 0;
        for(int j=0;j<temp.length();j++){
            if(temp[j] == '1'){
                sum+=public_key[j];
            }
        }
        cipher_text.push_back(sum);
    }

    for(int i=0;i<cipher_text.size();i++){
        cout<<cipher_text[i]<<" ";
    }

    cout<<endl;
    // Decryption

    int w_inverse = modInverse(w,M);

    string decrypted_message = "";
    for (int c : cipher_text) {
        
        int sum = (c * w_inverse) % M;
        string group_bits = "";

        // Decrypt by comparing with private key
        for (int i = grps - 1; i >= 0; i--) {
            if (sum >= private_key[i]) {
                sum -= private_key[i];
                group_bits = '1' + group_bits;
            } else {
                group_bits = '0' + group_bits;
            }
        }
        decrypted_message += group_bits;
    }

    cout<<"Decrypted Message: "<<decrypted_message<<endl;
    
}