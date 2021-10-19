#include <bits/stdc++.h>
using namespace std;

void exit(){
    cout<<"Matrices cannot be multiplied!";
}
int main(){
    int a01, b01, a02, b02;
    cin>>a01>>b01>>a02>>b02;
    int a1[a01][b01];
    int a2[a02][b02];
    for(int i=0;i<a01;i++){
        for(int j=0;j<b01;j++){
            cin>>a1[i][j];
        }
    }
    
    for(int i=0;i<a02;i++){
        for(int j=0;j<b02;j++){
            cin>>a2[i][j];
        }
    }
    
    if(b01 != a02){
        exit();
    }
    else{
        int a3[a01][b02];
        for(int i=0;i<a01;i++){
            for(int j=0;j<b02;j++){
                a3[i][j]=0;
                for(int k=0;k<b02;k++){
                   if(a1[i][k]%2==0 && a2[k][j]%2==0){
                        a3[i][j]+= a1[i][k]*a2[k][j];
                   }
                    else{
                        a3[i][j]+= a1[i][k];
                    }
                }
            }
        }
        
        for(int i=0;i<a01;i++){
            for(int j=0;j<b02;j++){
                cout<<a3[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
