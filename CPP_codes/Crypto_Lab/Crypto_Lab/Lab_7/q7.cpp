// Route Cipher
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain_text;
    int key, row, col;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the grid size: "<<endl;
    cin>>row>>col;
 
    vector<vector<char>> grid(row, vector<char>(col));

    int p=0,q=0;
    int h =0;
    for(int i=0;i<(row*col);i++){
        
        if(p == row){
            q++;
            p=0;
        }

        if(i >= plain_text.length()){
            grid[p][q] = char(65 + h);
            h++;
        }else{
            grid[p][q] = plain_text[i];
        }

        p++;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }  
    int up = 0;
    int down = row-1;
    int left = 0;
    int right = col-1;

    string encrypted_text="";
    while (up <= down && left <= right) {

        for (int i = up; i <= down; i++) {
            encrypted_text.push_back(grid[i][right]);
        }
        right--; 

        
        for (int i = right; i >= left; i--) {
            encrypted_text.push_back(grid[down][i]);
        }
        down--;
        

        if (left <= right) {
            for (int i = down; i >= up; i--) {
                encrypted_text.push_back(grid[i][left]);
            }
            left++;  
        }

        if (up <= down) {
            for (int i = left; i <= right; i++) {
                encrypted_text.push_back(grid[up][i]);
            }
            up++; 
        }
    }

    cout<<encrypted_text<<endl;


}