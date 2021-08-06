#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int &n, int &m, int i, int j, vector<vector<int>> &dp)
{
    if (i >= n || j >= m || i < 0)
        return 0;

    if (j == m - 1)
        return dp[i][j] = grid[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = grid[i][j] + max({helper(grid, n, m, i - 1, j + 1, dp), helper(grid, n, m, i, j + 1, dp), helper(grid, n, m, i + 1, j + 1, dp)});
}

int maxGold(int n, int m, vector<vector<int>> &grid)
{
    int start = -1;
    int max_start = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, helper(grid, n, m, i, 0, dp));
    }

    return ans;
}

int main()
{
    return 0;
}