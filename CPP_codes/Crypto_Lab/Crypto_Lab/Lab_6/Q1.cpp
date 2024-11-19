#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> generating_key_matrix(string key){

    unordered_map<char, bool> check_occurence;
    vector<vector<char>> matrix;
    int p = 0;
    vector<char> temp;

    for(int i = 0; i < key.length(); i++){
        if(!check_occurence[key[i]]){ 
            check_occurence[key[i]] = true; 

            temp.push_back(key[i]);
            p++;
            
            if(p % 5 == 0){  
                matrix.push_back(temp);
                temp.clear();
            }
        }
    }


    for(int i = 0; i < 26; i++){
        if(i == 9){  
            continue;
        }
        
        char current_char = char(i + 97);  

        if(!check_occurence[current_char]){  
            temp.push_back(current_char);
            p++;
            
            if(p % 5 == 0){  
                matrix.push_back(temp);
                temp.clear();
            }
        }
    }

    
    if(!temp.empty()){
        matrix.push_back(temp);
    }

    return matrix;

}
string add_x(string plain_text){
    
    int i=0;
    string x = "x";
    while(i!=plain_text.length()){
        
        char p1 = plain_text[i];
        char p2;
        if((i+1) != plain_text.length()){
            p2 = plain_text[i+1];
        }else{
            plain_text.insert(i+1,x);
        }

        if(p1 == p2){
            plain_text.insert(i+1,x);
            i=0;
        }else{
            i+=2;
        }

    }

    return plain_text;
}
pair<int,int> get_index(vector<vector<char>> matrix, char c){

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(c == matrix[i][j]){
                pair<int,int> p = {i,j};
                return p;
            }
        }
    }
}
int main()
{
    string key = "akash";
    vector<vector<char>> matrix = generating_key_matrix(key);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    string plain_text = "meetmeatthebridge";
    string new_plain_text = add_x(plain_text);

    // cout<<new_plain_text<<endl;

    int i=0;
    string cipher_text;
    while(i!= new_plain_text.length()){
        char c1 = new_plain_text[i];
        char c2 = new_plain_text[i+1];
        pair<int,int> p1 = get_index(matrix, c1);
        pair<int,int> p2 = get_index(matrix, c2);
        int i1 = p1.first;
        int j1 = p1.second;
        int i2 = p2.first;
        int j2 = p2.second;
        // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;

        char new_c1;
        char new_c2;
        if(i1 == i2){
            j1 = (j1+1)%5;
            j2 = (j2+1)%5;
            new_c1 = matrix[i1][j1];
            new_c2 = matrix[i2][j2];
        }else if(j1 == j2){
            i1 = (i1+1)%5;
            i2 = (i2+1)%5;
            new_c1 = matrix[i1][j1];
            new_c2 = matrix[i2][j2];
        }else{
            new_c1 = matrix[i1][j2];
            new_c2 = matrix[i2][j1];
        }

        cipher_text.push_back(new_c1);
        cipher_text.push_back(new_c2);
        i+=2;
    }

    cout<<"Cipher Text: "<<cipher_text<<endl;

    string decrypted_text;
    int j=0;
    while(j!= cipher_text.length()){
        char c1 = cipher_text[j];
        char c2 = cipher_text[j+1];
        pair<int,int> p1 = get_index(matrix, c1);
        pair<int,int> p2 = get_index(matrix, c2);
        int i1 = p1.first;
        int j1 = p1.second;
        int i2 = p2.first;
        int j2 = p2.second;
        // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;

        char new_c1;
        char new_c2;
        if(i1 == i2){
            j1 = (j1-1)%5;
            j2 = (j2-1)%5;
            new_c1 = matrix[i1][j1];
            new_c2 = matrix[i2][j2];
        }else if(j1 == j2){
            i1 = (i1-1)%5;
            i2 = (i2-1)%5;
            new_c1 = matrix[i1][j1];
            new_c2 = matrix[i2][j2];
        }else{
            new_c1 = matrix[i1][j2];
            new_c2 = matrix[i2][j1];
        }

        decrypted_text.push_back(new_c1);
        decrypted_text.push_back(new_c2);
        j+=2;
    }
    
    cout<<"Decrypted Text: "<<decrypted_text<<endl;
}
