#include<bits/stdc++.h>
using namespace std;
vector<int> decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    vector<int> vec;
    for (int j = i - 1; j >= 0; j--){
        vec.push_back(binaryNum[j]);
    }
    

    return vec;
    
}
vector<int> multiplyPolynomials(const vector<int>& poly1, const vector<int>& poly2) {
    int size1 = poly1.size();
    int size2 = poly2.size();
    vector<int> result(size1 + size2 - 1, 0);

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}
int main()
{
    int n = 16;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            unsigned int a = i^j;
            if(a == 0){
                cout<<"Additive Inverse of "<<i<<" is : "<<j<<endl;
            }
        }
    }
    vector<vector<int>> ans;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            vector<int> first = decToBinary(i);
            vector<int> second = decToBinary(j);
            for(int k=first.size();k<4;k++){
                first.insert(first.begin(),0);
            }
            for(int k=second.size();k<4;k++){
                second.insert(second.begin(),0);
            }
            // for (int k=0;k<first.size();k++){
            //     cout<<first[k]<<" ";
            // }
            // cout<<"     ";
            // for (int k=0;k<first.size();k++){
            //     cout<<second[k]<<" ";
            // }
            vector<int> result = multiplyPolynomials(first, second);
            // cout<<"     ";
            for (int k=0;k<result.size();k++){
                if(result[k]%2 == 0){
                    result[k] = 0;
                }else{
                    result[k] = 1;
                }
                // cout<<result[k]<<" ";
            }
            ans.push_back(result);
            // cout<<endl;

        }
    }

    for(int i=0;i<ans.size();i++){
        vector<int> irre_poly;
        
        if(ans[i][0] == 1){ // x^6
                irre_poly.push_back(1);
                irre_poly.push_back(0);
                irre_poly.push_back(0);
                irre_poly.push_back(1);
                irre_poly.push_back(1);
                irre_poly.push_back(0);
                irre_poly.push_back(0);

                for(int k = 0;k<7;k++){
                    if((ans[i][k] + irre_poly[k])%2 == 0){
                        ans[i][k] = 0;
                    }else{
                        ans[i][k] = 1;
                    }
                    
                }
        }

        if(ans[i][1] == 1){ // x^5
                irre_poly.clear();
                irre_poly.push_back(0);
                irre_poly.push_back(1);
                irre_poly.push_back(0);
                irre_poly.push_back(0);
                irre_poly.push_back(1);
                irre_poly.push_back(1);
                irre_poly.push_back(0);

                for(int k = 0;k<7;k++){
                    if((ans[i][k] + irre_poly[k])%2 == 0){
                        ans[i][k] = 0;
                    }else{
                        ans[i][k] = 1;
                    }
                    
                }
        }
        
        if(ans[i][2] == 1){ // x^4
                irre_poly.clear();
                irre_poly.push_back(0);
                irre_poly.push_back(0);
                irre_poly.push_back(1);
                irre_poly.push_back(0);
                irre_poly.push_back(0);
                irre_poly.push_back(1);
                irre_poly.push_back(1);

                for(int k = 0;k<7;k++){
                    if((ans[i][k] + irre_poly[k])%2 == 0){
                        ans[i][k] = 0;
                    }else{
                        ans[i][k] = 1;
                    }
                    
                }
            
        }
    }

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j];
    //     }
    //     cout<<endl;
    // }
    
    vector<int> inverses;

    for(int i=16;i<ans.size();i++){
        if((ans[i][6] == 1) && (ans[i][5] == 0) && (ans[i][4] == 0) && (ans[i][3] == 0)){
            inverses.push_back(i%16);
        }
    }

    cout<<inverses.size()<<endl;
    for(int i=0;i<inverses.size();i++){
        cout<<"Multiplicative Inverse of "<<i+1<<" is: "<<inverses[i]<<endl;
    }

    
}