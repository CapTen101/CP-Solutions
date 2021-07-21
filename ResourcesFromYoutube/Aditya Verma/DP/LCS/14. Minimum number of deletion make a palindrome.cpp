#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
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
    return dp[sl][tl];
}
int minimumNumberOfDeletions(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s.size() - lcs(s, rev);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}