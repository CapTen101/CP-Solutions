#include <bits/stdc++.h>
using namespace std;

int helper(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == m and j == n)
        return 1;

    if (i < m and j < n)
    {
        return dp[i][j] = helper(m, n, i + 1, j, dp) + helper(m, n, i, j + 1, dp);
    }
    else if (i == m and j < n)
    {
        return dp[i][j] = helper(m, n, i, j + 1, dp);
    }
    else
    {
        return dp[i][j] = helper(m, n, i + 1, j, dp);
    }
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(m, n, 1, 1, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}