// Feistel Cipher
#include<bits/stdc++.h>
using namespace std;
string apply_func(string r){
    string ans;
    for(int i=0;i<r.length();i+=3){
        char ch = r[i+2];
        string temp = r.substr(i,3);
        temp = ch+temp;
        temp.pop_back();
        ans+=temp;
    }

    return ans;
}
int main()
{
    string plain_text;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    int rounds; 
    cout<<"Enter the number of rounds: "<<endl;
    cin>>rounds;

    int l = plain_text.length();

    string left = plain_text.substr(0,l/2);
    string right = plain_text.substr(l/2,l);

    // ENCRYPTION
    // Let function be right shift operation
    for(int i=0;i<rounds;i++){
        string new_r = apply_func(right);
        string after_xor;
        for(int j=0;j<new_r.length();j++){
            if(left[j] == new_r[j]){
                after_xor+='0';
            }else{
                after_xor+='1';
            }
        }

        left = right;
        right = after_xor;

    }
    string cipher_text = left+right;
    cout<<"Encrypted Text: "<<cipher_text<<endl;


    // DECRYPTION
    string left1 = cipher_text.substr(0,l/2);
    string right1 = cipher_text.substr(l/2,l);
    for(int i=0;i<rounds;i++){
        string new_l = apply_func(left1);
        string after_xor;
        for(int j=0;j<new_l.length();j++){
            if(right1[j] == new_l[j]){
                after_xor+='0';
            }else{
                after_xor+='1';
            }
        }

        right1 = left1;
        left1 = after_xor;

    }
    string decrypted_text = left1+right1;
    cout<<"Decrypted Text: "<<decrypted_text<<endl;

}