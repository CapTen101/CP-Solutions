#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    if (s == p)
        return true;

    int sn = s.size();
    int pn = p.size();

    bool dp[pn + 1][sn + 1];
    memset(dp, false, sizeof(dp));

    dp[pn][sn] = true;

    for (int i = pn; i >= 0; i--)
    {
        for (int j = sn; j >= 0; j--)
        {
            if (i == pn and j == sn)
                dp[i][j] = true;
            else if (i == pn)
                dp[i][j] = false;
            else if (j == sn)
            {
                if (p[i] == '*')
                {
                    dp[i][j] = dp[i + 1][j]; // if true then good, otherwise it's already false
                }
            }
            else
            {
                if (p[i] == s[j] || p[i] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (p[i] == '*')
                {
                    /* SLOW WAY
                        int ki = i+1; // check in below row for atleast 1 true presence
                        int kj = j;
                        while(kj<sn)
                        {
                            if(dp[ki][kj]){
                                dp[i][j] = true;
                                break;
                            }
                            kj++;
                        }
                        */

                    // OPTIMIZED WAY:
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }
    }

    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}