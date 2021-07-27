#include <bits/stdc++.h>
using namespace std;

// here we need 3D matrix since 3 state variables are there
int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue] % 1003;

    // no element
    if (i > j)
        return dp[i][j][isTrue] = 0;

    // if single element is there
    if (i == j)
    {
        // if we need the expression to be true then check the single element
        if (isTrue)
            // if true, then return true
            return dp[i][j][isTrue] = int(s[i] == 'T');
        else
            // if false, then return false
            return dp[i][j][isTrue] = int(s[i] == 'F');
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        // int lt = solve(s, i, k - 1, true, dp);
        // int lf = solve(s, i, k - 1, false, dp);
        // int rt = solve(s, k + 1, j, true, dp);
        // int rf = solve(s, k + 1, j, false, dp);

        int lt, lf, rt, rf;

        if (dp[i][k - 1][true] != -1)
            lt = dp[i][k - 1][true];
        else
            lt = solve(s, i, k - 1, true, dp);

        if (dp[i][k - 1][false] != -1)
            lf = dp[i][k - 1][false];
        else
            lf = solve(s, i, k - 1, false, dp);

        if (dp[k + 1][j][true] != -1)
            rt = dp[k + 1][j][true];
        else
            rt = solve(s, k + 1, j, true, dp);

        if (dp[k + 1][j][false] != -1)
            rf = dp[k + 1][j][false];
        else
            rf = solve(s, k + 1, j, false, dp);

        // if the expression needs to be evaluated to true
        if (isTrue)
        {
            if (s[k] == '^') // XOR
            {
                ans += (lt * rf + lf * rt) % 1003;
            }
            else if (s[k] == '&') // AND
            {
                ans += (lt * rt) % 1003;
            }
            else // OR
            {
                ans += (lt * rf + lf * rt + lt * rt) % 1003;
            }
        }
        // else if the expression needs to be evaluated to false
        else
        {
            if (s[k] == '^') // XOR
            {
                ans += (lt * rt + lf * rf) % 1003;
            }
            else if (s[k] == '&') // AND
            {
                ans += (lf * rf + lf * rt + lt * rf) % 1003;
            }
            else // OR
            {
                ans += (lf * rf) % 1003;
            }
        }
    }

    return dp[i][j][isTrue] = ans % 1003;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
}