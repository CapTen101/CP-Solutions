#include <bits/stdc++.h>
using namespace std;

int helperMem(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (dp[n] = -1)
        return dp[n];
    if (n == 0)
        return 1;

    return dp[n] = helperMem(n - 1, dp) + helperMem(n - 2, dp);
}

int climbStairs(int n)
{
    // tabulation;
    /*
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
    */

    // memoization
    vector<int> dp(n, -1);
    return helperMem(n, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}