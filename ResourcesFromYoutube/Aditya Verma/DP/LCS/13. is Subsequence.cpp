#include <bits/stdc++.h>
using namespace std;

// Ultra basic approach but the fastest one
bool isSubsequence(string s, string t)
{
    int si = 0;
    int ti = 0;

    while (ti < t.size())
    {
        if (s[si] == t[ti])
        {
            si++;
            ti++;
        }
        else
        {
            ti++;
        }
    }

    if (si < s.size())
        return false;
    else
        return true;
}

// DP (LCS) way - check if lcs length is same as shorter string or not. that's it
bool isSubsequence(string s, string t)
{
    int sl = s.size();
    int tl = t.size();

    int dp[sl + 1][tl + 1];

    for (int i = 0; i <= sl; i++)
    {
        for (int j = 0; j <= tl; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[sl][tl] == sl ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}