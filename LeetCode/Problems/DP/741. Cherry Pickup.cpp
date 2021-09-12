#include <bits/stdc++.h>
using namespace std;

// 2 persons simultaneously going down in the grid approach -> https://leetcode.com/problems/cherry-pickup/discuss/329945/Very-easy-to-follow-%3A-step-by-step-recursive-backtracking-with-memoization-N4.

class Solution
{
public:
    int collect(vector<vector<int>> &grid, int &n, int r1, int c1, int c2, vector<vector<vector<int>>> &dp)
    {
        int r2 = r1 + c1 - c2; // same distance of both people from origin condition

        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        if (r1 == n - 1 and c1 == n - 1) // both are at bottom-right element
            return dp[r1][c1][c2] = grid[r1][c1];

        int cherry = grid[r1][c1];
        if (r1 != r2 and c1 != c2)
            cherry += grid[r2][c2];

        int down_down = collect(grid, n, r1 + 1, c1, c2, dp);
        int right_down = collect(grid, n, r1, c1 + 1, c2, dp);
        int right_right = collect(grid, n, r1, c1 + 1, c2 + 1, dp);
        int down_right = collect(grid, n, r1 + 1, c1, c2 + 1, dp);

        return dp[r1][c1][c2] = cherry + max({down_down, right_down, right_right, down_right});
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (n == 1)
            return grid[0][0] == 1 ? 1 : 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = collect(grid, n, 0, 0, 0, dp);

        return ans <= 0 ? 0 : ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}