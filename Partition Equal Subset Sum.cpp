/*
Partition Equal Subset Sum
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr + N, 0);
        if(sum & 1) return 0;
        vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
        dp[0][0] = true;

        for(int i = 1; i < N; i++) {
            for(int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                
                if(j - arr[i] >= 0)
                    dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i]];
            }
        }
        
        return (int) dp[N - 1][sum / 2];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
