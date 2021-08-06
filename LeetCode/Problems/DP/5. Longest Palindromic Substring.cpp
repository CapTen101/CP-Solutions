#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string str)
{
    int n = str.size();
    int dp[n][n];

    memset(dp, -1, sizeof(dp));

    // s -> starting index
    // e -> ending index
    // g -> gap between the starting and ending index
    // every g value represents a diagonal (g = 0 -> means i,i diagonal and g=1 means i,i+1 diagonal)

    pair<int, int> max_len_idx;
    int max_len = INT_MIN;
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
                max_len = max(max_len, j - i + 1);
                if (max_len == (j - i + 1))
                    max_len_idx = {i, j};
            }
        }
    }

    string ans = "";

    for (int i = max_len_idx.first; i <= max_len_idx.second; i++)
    {
        ans += str[i];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << longestPalindrome("aacabdkacaa") << endl;
}