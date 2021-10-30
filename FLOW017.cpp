// https://www.codechef.com/problems/FLOW017

#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--){
int a,b,c;
cin>>a>>b>>c;
if(c>a || c>b)
cout<<min(c,max(a,b))<<endl;
else
cout<<min(a,max(b,c))<<endl;
}}
