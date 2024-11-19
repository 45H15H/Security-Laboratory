#include<bits/stdc++.h>
using namespace std;
int main()
{
    int key;
    string s;
    cout<<"Enter the message: "<<endl;
    cin>>s;
    cout<<"Enter the key value: "<<endl;
    cin>>key;
    // cout<<s;
    vector<int> c_text;

    for(int i=0;i<s.length();i++){
        int val = int(s[i]) - 48;
        int x = (val+key)%36;
        c_text.push_back(x);
    }

    for(int i=0;i<c_text.size();i++){
        cout<<c_text[i]<<" ";
    }

    // string encrypted_text="";
    // for(int i=0;i<c_text.size();i++){
    //     encrypted_text+=char(c_text[i]+65);
    // }
    // cout<<"The encrypted text is: "<<encrypted_text<<endl;

    // string decryted_text="";
    // for(int i=0;i<c_text.size();i++){
    //     int val = c_text[i] - key;
    //     int x;
    //     if(val<0){
    //         x = val+26;
    //     }else{
    //         x = val;
    //     }

    //     decryted_text+=char(x+65);
    // }
    // cout<<"The decrypted text is: "<<decryted_text<<endl;
    
    
}