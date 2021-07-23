#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int solve(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &palindrome)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i >= j)
        return 0;

    if (isPalindrome(s, i, j))
    {
        dp[i][j] = 0;
        return 0;
    }

    // BASE CONDITION OVER, now loops.....

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // the 1 means no. of partitions from i->k + k+1->j and then one for between those two temp answers

        // check if one of the sub-problems are solved or not
        int left;
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
            left = solve(s, i, k, dp);
        if (left > ans) // optimization. if left is already larger than ans, then simply continue
            continue;

        int right;
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = solve(s, k + 1, j, dp);
        if (right > ans) // optimization.
            continue;

        // our temp_ans  = left + right + 1
        ans = min(ans, left + right + 1);
    }

    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string test = "aab";
    int n = test.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> palindrome(n + 1, vector<int>(n + 1, -1));
    return solve(test, 0, n - 1, dp);
}