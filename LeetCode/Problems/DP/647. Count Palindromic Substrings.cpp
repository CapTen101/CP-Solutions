#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string str)
{
    int n = str.size();
    int dp[n][n];

    int ans = 0;

    memset(dp, -1, sizeof(dp));

    // s -> starting index
    // e -> ending index
    // g -> gap between the starting and ending index
    // every g value represents a diagonal (g = 0 -> means i,i diagonal and g=1 means i,i+1 diagonal)

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0) // gap = 0 vala diagonal
                dp[i][j] = 1;
            else if (g == 1) // gap = 1 vala diagonal
                dp[i][j] = (str[i] == str[j]) ? 1 : 0;
            else
            {
                dp[i][j] = ((str[i] == str[j]) && (dp[i + 1][j - 1] == 1) ? 1 : 0);
            }

            // now in the end checking for dp[i][j] == 1 and recording the max length
            if (dp[i][j] == 1)
            {
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << countSubstrings("aaaaa") << endl;
}