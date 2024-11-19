#include<bits/stdc++.h>
using namespace std;
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
int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    // Return gcd of a and b 
    return result; 
} 
bool if_coprime(vector<int> m){
    for(int i=0;i<m.size()-1;i++){
        for(int j=i+1;j<m.size();j++){
            if(gcd(m[i], m[j])!=1){
                return false;
            }
        }
    }

    return true;
}
int main()
{   
    int n;
    vector<int> a;
    cout<<"Enter the number of remainders: "<<endl;
    cin>>n;
    cout<<"Enter the remainders: "<<endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    cout<<"Enter the moduli: "<<endl;
    vector<int> m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        m.push_back(temp);
    }

    if(if_coprime(m)){
        int M=1;
        for(int i=0;i<n;i++){
            M = M * m[i];
        }

        vector<int> M_cap;
        for(int i=0;i<n;i++){
            int temp;
            temp = (M/m[i]);
            cout<<temp<<" ";
            M_cap.push_back(temp);
        }

        int X=0;
        for(int i=0;i<n;i++){
            // cout<<"M.I"<<find_MI(M_cap[i], m[i])<<" ";
            X = (a[i]*M_cap[i]*find_MI(M_cap[i], m[i])) + X;
        }
    
        cout<<"The unique solution is: "<<X%M<<endl;
    }else{
        cout<<"The numbers are not coprime"<<endl;
    }   

    
}