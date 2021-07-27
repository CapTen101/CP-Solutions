#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int &m, int &n, int i, int j, vector<vector<int>> &dp)
{

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == (m - 1) and j == (n - 1))
        return dp[i][j] = 1;

    if (i < (m - 1) and j < (n - 1))
    {
        if ((grid[i + 1][j] != 1) and (grid[i][j + 1] != 1))
            return dp[i][j] = helper(grid, m, n, i + 1, j, dp) + helper(grid, m, n, i, j + 1, dp);
        else if (grid[i][j + 1] != 1)
            return dp[i][j] = helper(grid, m, n, i, j + 1, dp);
        else if (grid[i + 1][j] != 1)
            return dp[i][j] = helper(grid, m, n, i + 1, j, dp);
    }
    else if (i == (m - 1) and j < (n - 1))
    {
        if (grid[i][j + 1] != 1)
            return dp[i][j] = helper(grid, m, n, i, j + 1, dp);
    }
    else if (i < (m - 1) and j == (n - 1))
    {
        if (grid[i + 1][j] != 1)
            return dp[i][j] = helper(grid, m, n, i + 1, j, dp);
    }

    return dp[i][j] = 0;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    if (obstacleGrid[0][0] == 1)
        return 0;

    if (m == 1 and n == 1)
    {
        if (obstacleGrid[m - 1][n - 1])
            return 0;
        else
            return 1;
    }

    return helper(obstacleGrid, m, n, 0, 0, dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}