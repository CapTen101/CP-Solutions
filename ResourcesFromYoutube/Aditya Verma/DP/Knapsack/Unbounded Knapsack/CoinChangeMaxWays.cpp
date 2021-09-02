#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helperMemoization(int A, vector<int> &c, int n, vector<vector<int>> &dp)
    {
        if (A == 0)
            return 1;
        if (A < 0 || n == 0)
            return 0;

        if (dp[n][A] != -1)
        {
            return dp[n][A];
        }

        if (c[n - 1] <= A)
            return dp[n][A] = helperMemoization(A - c[n - 1], c, n, dp) + helperMemoization(A, c, n - 1, dp);
        else
            return dp[n][A] = helperMemoization(A, c, n - 1, dp);
    }

    int change(int A, vector<int> &c)
    {
        int n = c.size();

        // MEMOIZATION:
        // vector<vector<int>> dp(n + 1, vector<int>(A + 1, -1));
        // return helperMemoization(A, c, n, dp);

        // TABULATION:
        vector<vector<int>> dp(n + 1, vector<int>(A + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= A; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= A; j++)
            {
                if (c[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - c[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][A];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}