#include<iostream>
using namespace std;
 
int main()
{
    int rows;
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << endl;
 
    for (int i = 0; i < rows; i++)
    {
        int val = 1;
        for (int j = 1; j < (rows - i); j++)
        {
            cout << "   ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << "      " << val;
            val = val * (i - k) / (k + 1);
        }
        cout << endl << endl;
    }
    cout << endl;
    return 0;
}

// 2nd Approach with the help of Vector

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter No. of rows you want";
    cin>>n;
    vector<vector<int>> pascal(n);
    for(int i=0;i<n;i++){
        pascal[i].resize(i+1);
        pascal[i][0]=pascal[i][i]=1;
        for(int j=1;j<i;j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    
    for(auto i:pascal){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
