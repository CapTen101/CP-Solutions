#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, helper(grid, n, m, i, 0, dp)); // check for every row
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}