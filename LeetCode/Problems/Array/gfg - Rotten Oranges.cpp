#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int seconds = -1;
        int count_1 = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }

                if (grid[i][j] == 1)
                    count_1++;
            }
        }

        if (q.size() == 0)
            return -1;

        while (q.size())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if ((x - 1) < r and (x - 1) >= 0 and grid[x - 1][y] == 1)
                {
                    count_1--;
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if ((x + 1) < r and (x + 1) >= 0 and grid[x + 1][y] == 1)
                {
                    count_1--;
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if ((y - 1) < c and (y - 1) >= 0 and grid[x][y - 1] == 1)
                {
                    count_1--;
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
                if ((y + 1) < c and (y + 1) >= 0 and grid[x][y + 1] == 1)
                {
                    count_1--;
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }
            seconds++;
        }

        return count_1 == 0 ? seconds : -1;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}