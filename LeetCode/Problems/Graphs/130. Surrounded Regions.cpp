#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int &r, int &c, int i, int j)
{
    if (i >= r || j >= c || i < 0 || j < 0 || grid[i][j] != 'O')
        return;

    grid[i][j] = '#';

    dfs(grid, r, c, i, j + 1); // right
    dfs(grid, r, c, i + 1, j); // down
    dfs(grid, r, c, i, j - 1); // left
    dfs(grid, r, c, i - 1, j); // up
}

void solve(vector<vector<char>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    // first and last column
    for (int i = 0; i < r; i++)
    {
        if (grid[i][0] == 'O')
            dfs(grid, r, c, i, 0);
        if (grid[i][c - 1] == 'O')
            dfs(grid, r, c, i, c - 1);
    }

    // first and last row
    for (int j = 0; j < c; j++)
    {
        if (grid[0][j] == 'O')
            dfs(grid, r, c, 0, j);
        if (grid[r - 1][j] == 'O')
            dfs(grid, r, c, r - 1, j);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'O')
                grid[i][j] = 'X';
            if (grid[i][j] == '#')
                grid[i][j] = 'O';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}