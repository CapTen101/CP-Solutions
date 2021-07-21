#include <bits/stdc++.h>
using namespace std;

string printShortestCommonSupersequence(string s1, string s2)
{
    // LCS part
    int m = s1.size();
    int n = s2.size();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // NOW traversing the dp matrix similar to lcs fashion, to print it
    int i = m, j = n;
    vector<char> ans;

    while (i > 0 and j > 0)
    {
        // if equal, then include single one
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        // if chars are unequal, then include both since supersequence includes all characters
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans.push_back(s1[i - 1]); // why? (see below comment in quotes)
                i--;
            }
            else
            {
                ans.push_back(s2[j - 1]); // why? (see below comment in quotes)
                j--;
            }
        }
    }

    //reason for above addition to vector:
    /*
    "when t[i-1][j]>t[i][j-1] this is true then we move to upside of the current element in matrix because 
    t[i-1][j] is greater but when we move to upside we may lose the ith char of a(a[i-1])  so we will add 
    it first to ans , the j th char of b(b[j-1]) may be added later because we are still in same column of 
    current element(jth col). Similar reason when we move to left side of the current element in 
    matrix(t[i][j-1]>t[i-1][j])."
    */

    // NOW, either i=0 or j=0 or both are 0. so,
    // going until i=0 AND j=0
    // we need both zero since all elements must be the part of the supersequence
    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    string res = "";
    for (int i = ans.size() - 1; i >= 0; i--)
        res.push_back(ans[i]);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}