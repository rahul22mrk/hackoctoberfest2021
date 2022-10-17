// Top Down Approach

#include <iostream>
#include <unordered_map>
using namespace std;

int dp(int i)
{
    unordered_map<int, int> hash;
    // base cases
    if (i <= 2)
    {
        return i;
    }
    if (hash.find(i) == hash.end())
    {
        hash.insert({i, dp(i - 1) + dp(i - 2)});
    }
    return hash.at(i);
}

int climbingStairs(int n)
{
    return dp(n);
}

// Bottom Up Approach

int Climbing_stairs(int n)
{

    // An array that represents the answer to the problem for a given state
    int dp[10];
    // Base Cases
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    cout << Climbing_stairs(5);
}