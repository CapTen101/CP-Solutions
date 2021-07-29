#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int &m, int &n, int i, int j, int sum, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == (m - 1) and j == (n - 1))
        return grid[i][j];

    if (i < (m - 1) and j < (n - 1))
        return dp[i][j] = min(grid[i][j] + helper(grid, m, n, i + 1, j, sum + grid[i][j], dp), helper(grid, m, n, i, j + 1, sum + grid[i][j], dp) + grid[i][j]);

    else if (i < (m - 1) and j == (n - 1))
        return dp[i][j] = grid[i][j] + helper(grid, m, n, i + 1, j, sum + grid[i][j], dp);

    else
        return dp[i][j] = grid[i][j] + helper(grid, m, n, i, j + 1, sum + grid[i][j], dp);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (m == 1)
    {
        if (n == 1)
            return grid[0][0];
        else
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += grid[0][i];

            return sum;
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(grid, m, n, 0, 0, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}