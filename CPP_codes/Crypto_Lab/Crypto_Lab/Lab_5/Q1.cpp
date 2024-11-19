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
    vector<char> c_text={'0','1','2','3','4','5','6','7','8','9','A','B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' ,'V', 'W', 'X', 'Y', 'Z'};

    string encrypted_text="";
    for(int i=0;i<s.length();i++){ 
        char ch = s[i];
        int val;
        for(int j=0;j<c_text.size();j++){
            if(ch == c_text[j]){
                val = j;
            }
        }
        int x = (val+key)%36;
        char cp = c_text[x];
        encrypted_text.push_back(cp);
    }

    cout<<encrypted_text;
    
}