// leetcode: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());

    int sl = s.size();

    int dp[sl + 1][sl + 1];

    for (int i = 0; i <= sl; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= sl; i++)
    {
        for (int j = 1; j <= sl; j++)
        {
            if (s[i - 1] == rev[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return sl - dp[sl][sl];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}