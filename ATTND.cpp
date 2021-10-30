// https://www.codechef.com/problems/ATTND

#include <bits/stdc++.h>
using namespace std;

 int main()
 {
     int t;
     cin>>t;
     for(int i=0;i<t;i++)
     {
         int n,sum=0;
         cin>>n;
         string arr[n];
         string ar[n];
         for(int j=0;j<n;j++)
         cin>>arr[j]>>ar[j];
         for(int j=0;j<n;j++)
         {
             sum=0;
             for(int k=0;k<n;k++)
             {
                 if(j!=k)
                 {
                     if(arr[j]==arr[k])
                     sum++;
                 }
             }
             if(sum>0)
             cout<<arr[j]<<" "<<ar[j]<<endl;
             else
             cout<<arr[j]<<endl;
         }
     }
 }
