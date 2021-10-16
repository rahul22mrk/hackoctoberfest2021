#include<iostream>
using namespace std;

template<typename T>
void insertion(T arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        T key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={1,3,2,0,11,5,4};
    insertion(arr,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<endl;
}