#include <bits/stdc++.h>
using namespace std;
long long int solve(int it, int n, int y, long long int dp[][11])
{
    // first we'll handle all the extreme cases of first and the alst digit. (n+1 and 1 acc. to 1-based indexing)
    if (it == (n + 1))
    {
        long long int r = 1;
        return r;
    }
    if (dp[it][y] != -1)
    {
        return dp[it][y];
    }
    if (it == 1)
    {
        long long int op1 = solve(it + 1, n, 0, dp) + solve(it + 1, n, 1, dp) + solve(it + 1, n, 2, dp) + solve(it + 1, n, 3, dp) + solve(it + 1, n, 4, dp) + solve(it + 1, n, 5, dp) + solve(it + 1, n, 6, dp) + solve(it + 1, n, 7, dp) + solve(it + 1, n, 8, dp) + solve(it + 1, n, 9, dp);
        dp[it][y] = op1;
        return op1;
    }
    else
    {
        if (y == 0)
        {
            long long int op1 = solve(it + 1, n, 0, dp) + solve(it + 1, n, 8, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 1)
        {
            long long int op1 = solve(it + 1, n, 1, dp) + solve(it + 1, n, 2, dp) + solve(it + 1, n, 4, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 2)
        {
            long long int op1 = solve(it + 1, n, 2, dp) + solve(it + 1, n, 1, dp) + solve(it + 1, n, 3, dp) + solve(it + 1, n, 5, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 3)
        {
            long long int op1 = solve(it + 1, n, 3, dp) + solve(it + 1, n, 2, dp) + solve(it + 1, n, 6, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 4)
        {
            long long int op1 = solve(it + 1, n, 4, dp) + solve(it + 1, n, 1, dp) + solve(it + 1, n, 5, dp) + solve(it + 1, n, 7, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 5)
        {
            long long int op1 = solve(it + 1, n, 2, dp) + solve(it + 1, n, 4, dp) + solve(it + 1, n, 5, dp) + solve(it + 1, n, 6, dp) + solve(it + 1, n, 8, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 6)
        {
            long long int op1 = solve(it + 1, n, 3, dp) + solve(it + 1, n, 5, dp) + solve(it + 1, n, 9, dp) + solve(it + 1, n, 6, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 7)
        {
            long long int op1 = solve(it + 1, n, 7, dp) + solve(it + 1, n, 8, dp) + solve(it + 1, n, 4, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 8)
        {
            long long int op1 = solve(it + 1, n, 5, dp) + solve(it + 1, n, 7, dp) + solve(it + 1, n, 8, dp) + solve(it + 1, n, 9, dp) + solve(it + 1, n, 0, dp);
            dp[it][y] = op1;
            return op1;
        }
        else if (y == 9)
        {
            long long int op1 = solve(it + 1, n, 6, dp) + solve(it + 1, n, 8, dp) + solve(it + 1, n, 9, dp);
            dp[it][y] = op1;
            return op1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int it = 1; // can be zero also in case of 0-based indexing
        int y = 9;  // digit placed at the previous position

        long long int dp[n + 1][11];
        memset(dp, -1, sizeof(dp));

        cout << solve(it, n, y, dp) << endl;
    }
}