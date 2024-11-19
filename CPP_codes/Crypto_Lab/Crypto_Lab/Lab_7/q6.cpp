// Row column Cipher
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text;
    int row,col;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the grid size (row * column): "<<endl;
    cin>>row>>col;

    // Encryption
    vector<vector<char>> grid(row, vector<char> (col, '0'));
    int p = 0;
    int h = 0;
    int q=0;
    int l = row*col;
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

    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    string encrypted_text = "";

    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            encrypted_text+=grid[j][i];
        }
    }

    cout<<"Encrypted Text: "<<encrypted_text<<endl;


    // Decryption
    int k = 0;
    string decrypted_text;
    vector<vector<char>> grid2(row, vector<char> (col));
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            grid2[j][i] = encrypted_text[k];
            k++;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            decrypted_text+=grid2[i][j];
        }
    }
    cout<<"Decrypted Text: "<<decrypted_text<<endl;

}