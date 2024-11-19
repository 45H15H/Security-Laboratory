// Rail Fence Cipher
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text;
    int key;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the key: "<<endl;
    cin>>key;
    
    vector<vector<char>> grid(key, vector<char>(plain_text.length(),'0'));
    for(int i=0;i<plain_text.length();i++) {
        char c = plain_text[i];
        int row;
        if((i/(key-1))%2 == 0){
            row = (i%(key-1));
        }else{
            row = (key-1) - (i%(key-1));
        }

        // cout<<"check"<<endl;

        grid[row][i] = c;
    }

    string encrypted_text="";
    for(int i=0;i<key;i++){
        for(int j=0;j<plain_text.length();j++){
            if(grid[i][j] != '0'){
                encrypted_text+=grid[i][j];
            }
            // cout<<grid[i][j]<<" ";
        }
    }

    cout<<encrypted_text<<endl;
}