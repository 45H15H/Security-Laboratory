// One Time Pad
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text,key;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the key: "<<endl;
    cin>>key;

    if(plain_text.length() != key.length()){
        cout<<"Enter a valid key";
    }else{

        // Encryption
        string encrypted_text;
        for(int i=0;i<plain_text.length();i++){
            int x1 = int(plain_text[i]-'A');
            int x2 = int(key[i]-'A');
            int x = x1+x2;
            x = x%26;
            encrypted_text+=char(x+'A');
        }
        cout<<"Encrypted Text: "<<encrypted_text<<endl;

        // Decryption
        string decrypted_text;
        for(int i=0;i<encrypted_text.length();i++){
            int x1 = int(encrypted_text[i]-'A');
            int x2 = int(key[i]-'A');
            int x = x1-x2;
            if(x<0){
                x+=26;
            }
            x = x%26;
            decrypted_text+=char(x+'A');
        }
        cout<<"Decrypted Text: "<<decrypted_text<<endl;
    }
}