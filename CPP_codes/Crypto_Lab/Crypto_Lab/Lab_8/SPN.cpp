// SPN
// For m rounds, 
// Apply XOR, substitution and permutation for all m-2 rounds
// for 2nd last round, only perform XOR and substitution
// in last round, perform XOR with the final subkey
#include<bits/stdc++.h>
using namespace std;
vector<string> key_scheduling(string key, int l, int block_size, int rounds){
    vector<string> keys;

    int j = 0;
    int i = 0;
    while(j<rounds){
        string s = key.substr(i,l);
        keys.push_back(s);
        j++;
        i+=block_size;
    }

    return keys;
}
string substitution_func(string pt){
    unordered_map<string,string> map;
    map["0000"] = "1110";
    map["0001"] = "0100";
    map["0010"] = "1101";
    map["0011"] = "0001";
    map["0100"] = "0010";
    map["0101"] = "1111";
    map["0110"] = "1011";
    map["0111"] = "1000";
    map["1000"] = "0011";
    map["1001"] = "1010";
    map["1010"] = "0110";
    map["1011"] = "1100";
    map["1100"] = "0101";
    map["1101"] = "1001";
    map["1110"] = "0000";
    map["1111"] = "0111";

    string ans;
    for(int i=0;i<pt.length();i+=4){
        string s = pt.substr(i,4);
        string q = map[s];
        ans+=q;
    }

    return ans;
}
string inverse_substitution_func(string pt){
    unordered_map<string,string> map;
    map["1110"] = "0000";
    map["0100"] = "0001";
    map["1101"] = "0010";
    map["0001"] = "0011";
    map["0010"] = "0100";
    map["1111"] = "0101";
    map["1011"] = "0110";
    map["1000"] = "0111";
    map["0011"] = "1000";
    map["1010"] = "1001";
    map["0110"] = "1010";
    map["1100"] = "1011";
    map["0101"] = "1100";
    map["1001"] = "1101";
    map["0000"] = "1110";
    map["0111"] = "1111";

    string ans;
    for(int i=0;i<pt.length();i+=4){
        string s = pt.substr(i,4);
        string q = map[s];
        ans+=q;
    }

    return ans;
}
string permutation_func(string pt, int num_of_blocks, int pt_l){

    string ans;

    for(int i=0;i<num_of_blocks;i++){
        for(int j=i;j<pt_l;j+=num_of_blocks){
            ans+=pt[j];
        }
    }

    return ans;
}

int main()
{
    string plain_text;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    int num_of_blocks;
    cout<<"Enter the number of blocks: "<<endl;
    cin>>num_of_blocks;

    int plain_text_length = plain_text.length();
    int block_size = plain_text_length/num_of_blocks;

    int rounds; 
    cout<<"Enter the number of rounds: "<<endl;
    cin>>rounds;

    string key = "00111010100101001101011000111111"; 
    // cout<<"Enter the key: "<<endl;
    // cin>>key;

    vector<string> keys = key_scheduling(key,plain_text_length,num_of_blocks,rounds);


    // Encryption
    for(int i=0;i<rounds-1;i++){
        string key_to_use = keys[i];
        string new_pt;

        // XOR
        for(int j=0;j<plain_text_length;j++){
            if(key_to_use[j] == plain_text[j]){
                new_pt+='0';
            }else{
                new_pt+='1';
            }
        }

        string after_subs = substitution_func(new_pt);

        string after_permut;

        if(i<(rounds-2)){
            after_permut = permutation_func(after_subs, num_of_blocks, plain_text_length);
        }else{
            after_permut = after_subs;
        }
        plain_text = after_permut;
    }

    string cipher_text;
    string qw = keys[keys.size()-1];
    for(int j=0;j<plain_text_length;j++){
        if(qw[j] == plain_text[j]){
            cipher_text+='0';
        }else{
            cipher_text+='1';
        }
    }
    

    cout<<"Cipher Text: "<<cipher_text<<endl;



    // DECRYPTION
    string decrypted_text = cipher_text;
    cout << "Cipher Text: " << decrypted_text << endl;

    for(int i=rounds-1; i>=0; i--){
        string key_to_use = keys[i];
        string temp;

        
        if(i < (rounds - 2)){
            decrypted_text = permutation_func(decrypted_text, num_of_blocks, plain_text_length);
            // cout << "After Inverse Permutation (Round " << i+1 << "): " << decrypted_text << endl;
        }

        
        if(i < (rounds-1)){
            decrypted_text = inverse_substitution_func(decrypted_text);
            // cout << "After Inverse Substitution (Round " << i+1 << "): " << decrypted_text << endl;
        }

        
        for(int j=0; j<decrypted_text.length(); j++){
            if(key_to_use[j] == decrypted_text[j]){
                temp += '0';
            } else {
                temp += '1'; 
            }
        }

        decrypted_text = temp;
    }   

    cout<< "Decrypted Text: " << decrypted_text << endl;


}