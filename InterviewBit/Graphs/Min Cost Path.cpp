#include <bits/stdc++.h>
using namespace std;

int helper(int &r, int &c, int i, int j, vector<string> &grid)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return INT_MAX/2;

    if(i==r-1 && j==c-1)
        return 0;

    if(grid[i][j] == 'R')
    {
        return min({1+helper(r, c, i+1, j, grid), 1+helper(r,c,i-1,j, grid), 1+helper(r,c,i,j-1, grid), helper(r,c,i,j+1, grid)});
    }
    else if(grid[i][j] == 'U')
    {
        return min({1+helper(r, c, i+1, j, grid), helper(r,c,i-1,j, grid), 1+helper(r,c,i,j-1, grid), 1+helper(r,c,i,j+1, grid)});
    }
    else if(grid[i][j] == 'D')
    {
        return min({helper(r, c, i+1, j, grid), 1+helper(r,c,i-1,j, grid), 1+helper(r,c,i,j-1, grid), 1+helper(r,c,i,j+1, grid)});
    }
    else // 'L'
    {
        return min({1+helper(r, c, i+1, j, grid), 1+helper(r,c,i-1,j, grid), helper(r,c,i,j-1, grid), 1+helper(r,c,i,j+1, grid)});
    }
}

int solve(int r, int c, vector<string> &grid) {
    if(r==0 || c==0)
        return 0;

    return helper(r, c, 0, 0, grid);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> input = {"RRRRRRRRRR"};
    cout<<solve(1, 10, input);
}