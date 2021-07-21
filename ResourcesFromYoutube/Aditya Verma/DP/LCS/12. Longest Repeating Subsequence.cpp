#include <bits/stdc++.h>
using namespace std;

// problem: on gfg

int LongestRepeatingSubsequence(string s)
{
    string a = s;
    string b = s;
    int n = s.size();
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1] and i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}