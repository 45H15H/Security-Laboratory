    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int x1,x2;
        cout<<"Enter a number: "<<endl;
        cin>>x1;
        cout<<"Enter the value of n: "<<endl;
        cin>>x2;

        bool x = false;
        int c = 1;
        while(x != true){
            if((x1*c)%x2 == 1){
                cout<<"M.I of "<<x1<<" is "<<c<<endl;
                x = true;
            }else{
                c++;
            }
        }
    }