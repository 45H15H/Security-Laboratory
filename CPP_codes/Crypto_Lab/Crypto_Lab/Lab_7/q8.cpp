// Column Transposition
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text;
    string key, key2;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;
    cout<<"Enter the key: "<<endl;
    cin>>key;
    key2 = key;

    int col = key.length();
    int row;
    if(plain_text.length()%col == 0){
        row = plain_text.length()/col;
    }else{
        row = plain_text.length()/col + 1;
    }


    // Encryption
    int p = 0;
    int h = 0;
    int q=0;
    cout<<"Row: "<<row<<" Col: "<<col<<endl;
    vector<vector<char>> grid(row, vector<char>(col));
    for(int i=0;i<(row*col);i++){
        
        if(q == col){
            p++;
            q=0;
        }

        if(i >= plain_text.length()){
            grid[p][q] = char(65 + h);
            h++;
        }else{
            grid[p][q] = plain_text[i];
        }

        q++;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    unordered_map<char, vector<char>> alpha_map;
    for(int i=0;i<key.length();i++){
        for(int j=0;j<row;j++){
            alpha_map[key[i]].push_back(grid[j][i]);
        }
    }


    sort(key.begin(),key.end());

    string encrypted_text;
    for(int i=0;i<key.length();i++){
        char ch = key[i];
        for(int j=0;j<row;j++){
            encrypted_text+=alpha_map[ch][j];
        }
    }

    cout<<"Encrypted Text: "<<encrypted_text;


    // Decryption
    vector<vector<char>> grid_2(row, vector<char>(col));
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            grid_2[j][i] = alpha_map[key2[i]][j];
        }
    }

    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<grid_2[i][j]<<" ";
        }
        cout<<endl;
    }

    string decrypted_text;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            decrypted_text+=grid_2[i][j];
        }
    }
    cout<<"Decrypted Text: "<<decrypted_text;

}