#include <bits/stdc++.h>
using namespace std;

int helper(string &s, string &t, int si, int ti, vector<vector<int>> &dp)
{
    if (ti == t.size())
        return 1;
    else if (si == s.size())
        return 0;

    if (dp[si][ti] != -1)
        return dp[si][ti];

    if (s[si] == t[ti])
    {
        return dp[si][ti] = helper(s, t, si + 1, ti, dp) + helper(s, t, si + 1, ti + 1, dp);
    }
    else
    {
        return dp[si][ti] = helper(s, t, si + 1, ti, dp);
    }
}

int numDistinct(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(s, t, 0, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}