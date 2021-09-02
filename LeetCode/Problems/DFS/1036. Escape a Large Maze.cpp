#include <bits/stdc++.h>
using namespace std;

// check this comment for clarity over the solution: https://leetcode.com/problems/escape-a-large-maze/discuss/971283/Just-a-description-of-the-solution-NO-CODE
/*

You want to traverse from a src point to a target point but there are certain blocks that are not accessible.
This would have been a very easy dfs/bfs problem, had the max array length had not been 10^6

There is a hacky solution which takes into consideration the blocked list length constraint which is only 200.
Its going to be hard to block a element from traversal in 10^ by 10^6 grid with only max 200 blocks

Therefore, we do normal bfs from source to target and check 2 conditions
1. Whether we have reached target
2. Whether we have exceeded 200 distance, here distance is calculated using manhattan distance, |(diff of x)| + |(diff of y)|
If any of above is true, then return result true.

But wait, what if blocked points are not trying to surround source point but have surrounded the target point?

For above, scenario we again do a bfs bt this time from target to source, if we are able to reach now , we return true.

Only if both traversal return true then we can truly escape.............

Also first check should be whether the src/target point lie on blocked list if yes, then escape is impossible

*/

class Solution
{
public:
    bool dfs(unordered_multimap<int, int> &blocked, vector<int> &source, vector<int> &target, int &r, int &c, int i, int j)
    {
        if (i >= r || j >= c || i < 0 || j < 0)
            return false;

        auto umit = blocked.find(i);
        if (umit != blocked.end() and umit->second == j)
            return false;

        if (i == target[0] and j == target[1] || abs(i - source[0]) + abs(j - source[1]) > 200)
            return true;

        bool north = dfs(blocked, source, target, r, c, i - 1, j);
        bool south = dfs(blocked, source, target, r, c, i + 1, j);
        bool east = dfs(blocked, source, target, r, c, i, j - 1);
        bool west = dfs(blocked, source, target, r, c, i, j + 1);

        return north || south || east || west;
    }
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        unordered_multimap<int, int> umm;
        for (int i = 0; i < blocked.size(); i++)
        {
            if ((source[0] == blocked[i][0] and source[1] == blocked[i][1]) || (target[0] == blocked[i][0] and target[1] == blocked[i][1]))
                return false;
            umm.insert({blocked[i][0], blocked[i][1]});
        }

        int r = 1000000;
        int c = 1000000;

        // dfs from src -> target && dfs from target -> src (check above comment)
        return dfs(umm, source, target, r, c, source[0], source[1]) && dfs(umm, target, source, r, c, target[0], target[1]);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}