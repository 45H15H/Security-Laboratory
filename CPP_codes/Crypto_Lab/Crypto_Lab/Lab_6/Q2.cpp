#include<bits/stdc++.h>
using namespace std;
int determinant(int n , vector<vector<int>> a) {
    int det = (a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])) - (a[0][1]*(a[1][0]*a[2][2] - a[2][0]*a[1][2])) + (a[0][2]*(a[1][0]*a[2][1] - a[2][0]*a[1][1]));
	return det;
}
int find_MI(int x1, int x2){

    bool x = false;
        int c = 1;
        while(x != true){
            if((x1*c)%x2 == 1){   
                x = true;
            }else{
                c++;
            }
        }
    return c;
}
int main()
{
    string key = "gybnqkurp";
    // string key = "rrfvsvcct";
    
    vector<vector<int>> key_matrix;
    int p=0;
    vector<int> temp;
    for(int i=0;i<key.length();i++){
        temp.push_back(int(key[i])-97);
        p++;
        if(p%3 == 0){
            key_matrix.push_back(temp);
            temp.clear();
        }
    }

    // for(int i=0;i<key_matrix.size();i++){
    //     for(int j=0;j<key_matrix[i].size();j++){
    //         cout<<key_matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    string plain_text = "paymoremoney";
    if((plain_text.length())%3 == 1){
        plain_text.push_back('x');
        plain_text.push_back('x');
    }else if((plain_text.length())%3 == 2){
        plain_text.push_back('x');
    }
    // cout<<plain_text;

    int i=0;
    string cipher_text;
    while(i!=plain_text.length()){
        int c1 = int(plain_text[i]-97);
        int c2 = int(plain_text[i+1]-97);
        int c3 = int(plain_text[i+2]-97);

        for(int j=0;j<3;j++){
            int val = c1*key_matrix[0][j] + c2*key_matrix[1][j] + c3*key_matrix[2][j];
            int val2 = (val%26) +97;
            cipher_text.push_back(char(val2));
        }
        i+=3;
    }

    cout<<"Cipher Text: "<<cipher_text<<endl;

    // Decryption
    int n = key_matrix.size();
    int det = determinant(n, key_matrix);
    if(det < 0){
        int x = det*-1;
        det = 26 - (x%26);
    }

    int det_inv = find_MI(det,26);
    vector<vector<int>> cof;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x = i;
            int y = j;
            int x1,x2;
            int y1,y2;
            if(x == 0){
                x1 = 1;
                x2 = 2;
            }else if(x == 1){
                x1 = 0;
                x2 = 2;
            }else{
                x1 = 0;
                x2 = 1;
            }

            if(y == 0){
                y1 = 1;
                y2 = 2;
            }else if(y == 1){
                y1 = 0;
                y2 = 2;
            }else{
                y1 = 0;
                y2 = 1;
            }
            int val = key_matrix[x1][y1]*key_matrix[x2][y2] - key_matrix[x1][y2]*key_matrix[x2][y1];
            if((x+y)%2 != 0){
                val = val*-1;
            }
            temp.push_back(val);
        }
        cof.push_back(temp);
    }

    
    // Transpose matrix
    vector<vector<int>> k_inverse;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(cof[j][i]);
        }
        k_inverse.push_back(temp);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int fg = k_inverse[i][j];
            if(fg < 0){
                int x = fg*-1;
                fg = 26 - (x%26);
                k_inverse[i][j] = fg;
            }else{
                k_inverse[i][j] = (k_inverse[i][j])%26;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int fg = k_inverse[i][j]*det_inv;
            k_inverse[i][j] = fg%26;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<k_inverse[i][j]<<" ";
        }
        cout<<endl;
    }


    string decrypted_text="";
    i=0;
    while(i!=cipher_text.length()){
        int c1 = int(cipher_text[i]-97);
        int c2 = int(cipher_text[i+1]-97);
        int c3 = int(cipher_text[i+2]-97);

        for(int j=0;j<3;j++){
            int val = c1*k_inverse[0][j] + c2*k_inverse[1][j] + c3*k_inverse[2][j];
            int val2 = (val%26) +97;
            // cout<<val2<<" ";
            decrypted_text.push_back(char(val2));
        }
        i+=3;
    }

    cout<<"Decrypted Text: "<<decrypted_text;
    
}