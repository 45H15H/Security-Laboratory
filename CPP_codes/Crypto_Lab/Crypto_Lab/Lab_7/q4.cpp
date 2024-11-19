// Affine Cipher
#include<bits/stdc++.h>
using namespace std;

int find_MI(int a,int n){
    int x1,x2;
    x2 = n;
    x1 = a;

    int r1,r2;
    // a is the largest number out of the two
    if(r1>r2){
        r1 = x1;
        r2 = x2;
        x1 = r1;
        x2 = r2;
    }else{
        r1 = x2;
        r2 = x1;
        x1 = r2;
        x2 = r1;
    }

    int r = r1%r2;
    int q = r1/r2;
    int t1 = 1, t2 = 0, s1 = 0, s2 = 1;
    int t = t1 - (q*t2);
    int s = s1 - (q*s2);

    while(r!=0){
        r1 = r2;
        r2 = r;

        t1 = t2;
        t2 = t;

        s1 = s2;
        s2 = s;

        q = r1/r2;
        r = r1%r2;
        t = t1 - (q*t2);
        s = s1 - (q*s2);
    }
    

    if(s2 > 0){
        // cout<<"M.I is: "<<s2<<endl;
        return s2;
    }else{
        // cout<<"M.I is: "<<s2+n<<endl;
        return (s2+n);
    }
}
int main()
{
    string plain_text;
    int a,b;
    cout<<"Enter the plain text: "<<endl;
    cin>>plain_text;

    cout<<"Enter the parameters 'a' and 'b': "<<endl;
    cin>>a>>b;

    // Encryption
    string encrypted_text;
    for(int i=0;i<plain_text.length();i++){
        int p = int(plain_text[i]-'A');
        int val = (a*p + b)%26;
        encrypted_text+=char(val+'A');
    }

    cout<<"Encrypted Text: "<<encrypted_text<<endl;

    // Decryption
    string decrypted_text;
    int mi = find_MI(a,26);
    for(int i=0;i<encrypted_text.length();i++){
        int c = int(encrypted_text[i]-'A');
        int temp1 = c-b;
        if(temp1 < 0){
            temp1 = temp1+26;
        }
        int val = (mi*temp1)%26;
        decrypted_text+=char(val+'A');
    }
    cout<<"Decrypted Text: "<<decrypted_text<<endl;
}