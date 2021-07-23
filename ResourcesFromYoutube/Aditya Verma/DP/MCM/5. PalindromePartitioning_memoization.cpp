#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
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

int solve(string s, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    // if length is 0 or 1, then 0 partition can be done, hence return 0
    if (i >= j)
        return 0;

    // also check if string is a palindorm or not.
    // if yes, then no need to partition this palindrome
    if (isPalindrome(s, i, j))
    {
        dp[i][j] = 0;
        return 0;
    }

    // BASE CONDITION OVER, now loops.....

    // k goes from i ->j-1.
    // why (j-1)? => because  i->k and k+1->j requires k till j-1 only
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // the 1 means no. of partitions from i->k + k+1->j and then one for between those two temp answers
        int temp_ans = solve(s, i, k, dp) + solve(s, k + 1, j, dp) + 1;
        ans = min(ans, temp_ans);
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
    return solve(test, 0, n - 1, dp);
}