#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helperRecursive(int val[], int wt[], int n, int N)
    {
        if (n == 0 || N == 0)
            return 0;

        if (wt[n - 1] <= N)
            return max(helperRecursive(val, wt, n - 1, N), val[n - 1] + helperRecursive(val, wt, n, N - wt[n - 1]));
        else
            return helperRecursive(val, wt, n - 1, N);
    }

    int helperMemoization(int val[], int wt[], int n, int N, vector<vector<int>> &dp)
    {
        if (n == 0 || N == 0)
            return 0;

        if (dp[n][N] != -1)
            return dp[n][N];

        if (wt[n - 1] <= N)
            return dp[n][N] = max(helperMemoization(val, wt, n - 1, N, dp), val[n - 1] + helperMemoization(val, wt, n, N - wt[n - 1], dp));

        else
            return dp[n][N] = helperMemoization(val, wt, n - 1, N, dp);
    }

    int cutRod(int val[], int n)
    {
        /* RECURSIVE:
        int wt[n];
        for (int i = 0; i < n; i++)
            wt[i] = i + 1;

        return helperRecursive(val, wt, n, n);
        */

        /* MEMOIZATION
        int wt[n];
        for (int i = 0; i < n; i++)
            wt[i] = i + 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return helperMemoization(val, wt, n, n, dp);
        */

        // TABUALTION:
        int wt[n];
        for (int i = 0; i < n; i++)
            wt[i] = i + 1;

        int N = n;

        vector<vector<int>> dp(n + 1, vector<int>(N + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 0; i <= N; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (wt[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}