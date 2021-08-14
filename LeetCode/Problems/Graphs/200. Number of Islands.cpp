#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int &r, int &c, int i, int j)
{
    if (i >= r || j >= c || i < 0 || j < 0 || grid[i][j] != '1')
        return;

    grid[i][j] = '2';

    dfs(grid, r, c, i, j + 1); // right
    dfs(grid, r, c, i + 1, j); // down
    dfs(grid, r, c, i, j - 1); // left
    dfs(grid, r, c, i - 1, j); // up
}

int numIslands(vector<vector<char>> &grid)
{
    // for Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r = grid.size();
    int c = grid[0].size();

    int islands = 0;

    /*
            grid[i][j] = 0 -> water
            grid[i][j] = 1 -> island -> not discovered
            grid[i][j] = 2 -> island -> marked and discovered
        */

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                dfs(grid, r, c, i, j);
            }
        }
    }

    return islands;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}