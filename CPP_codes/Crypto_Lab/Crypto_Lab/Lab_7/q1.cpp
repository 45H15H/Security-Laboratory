// Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text,key;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the key: "<<endl;
    cin>>key;

    int len_key = key.length();

    // Encyption
    vector<int> c_text;
    string cipher;
    for(int i=0;i<plain_text.length();i++){
        int val = int(plain_text[i] - 'A') + int(key[i%len_key] - 'A');
        int val2 = val%26;
        c_text.push_back(val2);
    }

    for(int i=0;i<c_text.size();i++){
        cipher+=char(c_text[i]+'A');
    }

    cout<<"Encypted Text: "<<cipher<<endl;

    // Decryption
    string plain;
    for(int i=0;i<c_text.size();i++){
        int val = c_text[i] - int(key[i%len_key] - 'A');
        if(val<0){
            val+=26;
        }

        plain+=char(val+'A');
    }

    cout<<"Decrypted Text: "<<plain;
}