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
    int n;
    cout<<"Enter the size of matrix: "<<endl;
    cin>>n;

    int q;
    cout<<"Enter the mod value: "<<endl;
    cin>>q;

    cout<<"Enter the elements of the matrix: "<<endl;
    vector<vector<int>> mat;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            temp.push_back(p);
        }
        mat.push_back(temp);
    }

    int det = determinant(n,mat);
    if(det < 0){
        int x = det*-1;
        det = q - (x%q);
    }

    cout<<"Det: "<<det<<endl;

    // Calulating the matrix of cofactors
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
            int val = mat[x1][y1]*mat[x2][y2] - mat[x1][y2]*mat[x2][y1];
            if((x+y)%2 != 0){
                val = val*-1;
            }
            temp.push_back(val);
        }
        cof.push_back(temp);
    }

    
    // Transpose matrix
    vector<vector<int>> trans;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(cof[j][i]);
        }
        trans.push_back(temp);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int det_inv = find_MI(det,q);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            trans[i][j] = (trans[i][j] * det_inv);
            if(trans[i][j] < 0){
                int x = trans[i][j]*-1;
                trans[i][j] = q - (x%q);
            }else{
                trans[i][j] = (trans[i][j] * det_inv)%q;
            }
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }

}