#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    vector<int>values,weights;
    for(int i = 0;i < n;i ++)
    {
        int a;cin >> a;
        values.push_back(a);
    }
    for(int i = 0;i < n;i ++)
    {
        int a;cin >> a;
        weights.push_back(a);
    }
    int target;cin >> target;
    int **dp = new int *[n + 1];
    for(int i = 0;i < n + 1;i ++)
    {
        dp[i] = new int [target + 1];
    }
    for(int i = 0; i <= target;i ++)
    {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n;i ++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= target;j ++)
        {
            if(j >= weights[i - 1])
            {
                if(dp[i - 1][j - weights[i - 1]] + values[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j - weights[i - 1]] + values[i - 1];
                }
                else
                {
                    dp[i][j]= dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j]= dp[i - 1][j];
            }
        }
    }
    cout << dp[n][target]
}