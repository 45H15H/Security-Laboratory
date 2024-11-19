#include<bits/stdc++.h>
using namespace std;
int main()
{
    string cipher_text = "JXUSQJYIEKJEVJXURQW";
    // string cipher_text = "HPHTWWXPPELXTOYTRSE";

    vector<int> c_text;
    for(int i=0;i<cipher_text.length();i++){
        int val = int(cipher_text[i] - 65);
        // cout<<val<<" ";
        c_text.push_back(val);
    }
    
    for(int i=1;i<=25;i++){
        int key = i;

        string decryted_text="";
        for(int i=0;i<c_text.size();i++){
            int val = c_text[i] - key;
            int x;
            if(val<0){
                x = val+26;
            }else{
                x = val;
            }

            decryted_text+=char(x+65);
        }
        cout<<"The decrypted text for key "<<key<<" is: "<<decryted_text<<endl;
    }
    
    // key = 9
    // A stich in nine saves time
}