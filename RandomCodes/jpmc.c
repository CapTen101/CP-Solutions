#include <stdio.h>

// class Solution
// {
// public:
//     int DFS(vector<vector<int>> &grid, int x, int y, int &i, int &j)
//     {
//         if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size())
//             return 1001;

//         if (grid[x][y] != -1)
//         {
//             int right = DFS(grid, x, y + 1, i, j);
//             int bottom = DFS(grid, x + 1, y, i, j);
//             int top = DFS(grid, x - 1, y, i, j);
//             int left = DFS(grid, x, y - 1, i, j);

//             return min({right, bottom, top, left});
//         }
//         else
//         {
//             return abs(x - i) + abs(y - j);
//         }
//     }

//     vector<vector<int>> nearest(vector<vector<int>> &grid)
//     {
//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 if (grid[i][j] == 1)
//                     grid[i][j] = -1;
//             }
//         }

//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     grid[i][j] = DFS(grid, i, j, i, j);
//                 }
//             }
//         }

//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 if (grid[i][j] == -1)
//                 {
//                     grid[i][j] = 0;
//                 }
//             }
//         }

//         return grid;
//     }
// };

int a, b, c = 0;
void prtFun(void);

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int a = 1;
    prtFun();
    a += 1;
    prtFun();
    printf("\n %d %d", a, b);
}

void prtFun(void)
{
    register int a = 2;
    int b = 1;
    a += ++b;
    printf("\n %d %d", a, b);
}