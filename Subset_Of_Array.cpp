 //SOLVED USING BINARY METHOD...
#include<iostream>
#include<bits/stdc++.h>

#define ull unsigned long long int
using namespace std;
int dectobinary(int i){
    if(i==0)
        return 0;
    else 
        return i%2+10*(dectobinary(i/2));
}

 int main(){
    int n,count=0,k=0,rem;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<pow(2,n);i++){
        int a=dectobinary(i);
        int div=pow(10,n-1)+1;//g++ compiler return 10^2 as 99 
        for(int j=0;j<n;j++)
        {
            int q=a/div;
            int r=a%div;
            if(q==0)
                cout<<"";
            else
                cout<<arr[j]<<" ";
            a=r;
            div=div/10;
        }
        cout<<endl;
    }
 }