#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &t, int &m, int &n, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == (m - 1))
        return t[i][j];

    return dp[i][j] = min(t[i][j] + helper(t, m, n, i + 1, j, dp), t[i][j] + helper(t, m, n, i + 1, j + 1, dp));
}

int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    int n = t[m - 1].size();

    if (m == 1)
        return t[0][0];

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(t, m, n, 0, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}