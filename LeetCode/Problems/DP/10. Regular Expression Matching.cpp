#include <bits/stdc++.h>
using namespace std;

/*
1, If p[i-1] == s[j-1]  ->  dp[i][j] = dp[i-1][j-1];
2, If p[i-1] == '.'  ->  dp[i][j] = dp[i-1][j-1];
3, If p[i-1] == '*' :
   There are two possible conditions in such case:
               1   if p[i-2] != s[j-1] and p[i-2] != '.'  ->  dp[i][j] = dp[i-2][j]  // in this case, a* counts as empty
               2   if p[i-2] == s[j-1] or p[i-2] == '.':
                              dp[i][j] = dp[i-2][j]    //in this case, a* counts as empty 
                           or dp[i][j] = dp[i-2][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as multiple a

*/

bool isMatch(string s, string p)
{
    int sn = s.size();
    int pn = p.size();

    if (sn == 0 and pn == 0)
        return true;
    if (sn == 0 || pn == 0)
        return false;

    bool dp[pn + 1][sn + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int i = 2; i <= pn; i++)
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 2][0]; // look for two rows above

    for (int i = 1; i <= pn; i++)
    {
        for (int j = 1; j <= sn; j++)
        {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1]; // character match
            else if (p[i - 1] == '*')
            {
                if ((p[i - 2] != s[j - 1]) and p[i - 2] != '.')
                    dp[i][j] = dp[i - 2][j];
                else
                    dp[i][j] = dp[i - 2][j] || dp[i - 2][j - 1] || dp[i][j - 1]; // three possible cases
            }
        }
    }

    return dp[pn][sn];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}