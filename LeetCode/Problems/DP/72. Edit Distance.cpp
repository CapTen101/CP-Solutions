#include <bits/stdc++.h>
using namespace std;

int minDistance(string a, string b)
{
    int an = a.size();
    int bn = b.size();

    int dp[an + 1][bn + 1];

    for (int i = 0; i <= an; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= bn; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= an; i++)
    {
        for (int j = 1; j <= bn; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    return dp[an][bn];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}