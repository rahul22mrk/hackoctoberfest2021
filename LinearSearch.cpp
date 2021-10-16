#include<iostream>
using namespace std;

bool linear(int arr[],int n,int x){
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return true;
    }
    return false;
}

int main(){
    int arr[]={1,2,3,6,0};
    int a;
    cin>>a;
    a=5;
    if(linear(arr,a,0))
        cout<<"FOUND";
    else
        cout<<"NOT FOUND";
}