#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string: "<<endl;
    cin>>s;

    vector<char> subst;
    cout<<"Enter the replacement of each character starting from A: "<<endl;
    for(int i=0;i<26;i++){
        char ch;
        // cout<<"Enter the letter that will be replaced with "<<char(65+i)<<endl;
        cin>>ch;
        subst.push_back(ch);
    }
    // B C D E F G H I J K L M N O P Q R S T U V W X Y Z A

    string encrypted;
    cout<<"Encrypted String: ";
    for(int i=0;i<s.length();i++){
        int val = int(s[i]-65);
        encrypted+=subst[val];
    }

    cout<<encrypted;
}