#include <bits/stdc++.h>
using namespace std;

int helper(int e, int f, vector<vector<int>> &dp)
{
    if (dp[e][f] != -1)
        return dp[e][f];

    if (f == 0 || f == 1)
    {
        dp[e][f] = f;
        return f;
    }

    if (e == 1)
    {
        dp[e][f] = f;
        return f;
    }

    int ans = INT_MAX;

    // Linear search - slow
    // for (int k = 1; k <= f; k++)
    // {
    //     ans = min(ans, max(helper(e - 1, k - 1, dp), helper(e, f - k, dp)) + 1);
    // }

    // Binary Search:
    int l = 1, h = f;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int left = helper(e - 1, mid - 1, dp);
        int right = helper(e, f - mid, dp);
        if (left > right)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        ans = min(ans, max(left, right) + 1);
    }

    /* from this page: https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN)
    ANOTHER MORE optimized solution:

    vector<vector<int>> dp(f + 1, vector<int>(e + 1, 0));
    int m = 0;
    while (dp[m][e] < f)
    {
        m++;
        for (int k = 1; k <= e; ++k)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    return m;

    */

    // min? -> Since we require minimum number of attempts to find the threshold floor
    // max? -> Since we need the highest(max) floor possible which won't break the egg. hence we have to look for the worst case possible.
    //         In another way, we need the determine with CERTAINTY and GUARANTEE that the egg will break at the threshold floor hence take the worst case possible.

    return dp[e][f] = ans;
}

int solve(int e, int f, vector<vector<int>> &dp)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return helper(e, f, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}