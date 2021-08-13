#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int n, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return dp[i][j] = grid[i][j];

    return dp[i][j] = grid[i][j] + max({helper(grid, n, i + 1, j, dp), helper(grid, n, i + 1, j - 1, dp), helper(grid, n, i + 1, j + 1, dp)});
}

int maximumPath(int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = -1;
    for (int j = 0; j < n; j++)
    {
        ans = max(ans, helper(grid, n, 0, j, dp));
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}