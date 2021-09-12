#include <bits/stdc++.h>
using namespace std;

// best solution on Leetcode: https://leetcode.com/problems/dungeon-game/discuss/745340/post-Dedicated-to-beginners-of-DP-or-have-no-clue-how-to-start

class Solution
{
public:
    // similar to min-cost path
    int helper(vector<vector<int>> &grid, int &r, int &c, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0 || i >= r || j >= c)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        // return minimum health needed to enter princess' room
        if (i == (r - 1) and j == (c - 1))
            return dp[i][j] = grid[i][j] <= 0 ? -1 * grid[i][j] + 1 : 1;

        int right = helper(grid, r, c, i, j + 1, dp);
        int down = helper(grid, r, c, i + 1, j, dp);

        int minhealth = min(right, down) - grid[i][j];

        return dp[i][j] = (minhealth <= 0) ? 1 : minhealth;
    }
    int calculateMinimumHP(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        return helper(grid, r, c, 0, 0, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}