#include <bits/stdc++.h>
using namespace std;

long long helper(int n, int num, vector<vector<long long>> &dp)
{
    if (dp[n][num] != -1)
        return dp[n][num];

    if (n == 1)
        return 1;

    if (num == 0)
        return dp[n][num] = helper(n - 1, 8, dp) + helper(n - 1, 0, dp);
    else if (num == 1 || num == 3 || num == 7 || num == 9)
    {
        if (num == 1)
            return dp[n][num] = helper(n - 1, 2, dp) + helper(n - 1, 4, dp) + helper(n - 1, 1, dp);
        else if (num == 3)
            return dp[n][num] = helper(n - 1, 2, dp) + helper(n - 1, 6, dp) + helper(n - 1, 3, dp);
        else if (num == 7)
            return dp[n][num] = helper(n - 1, 8, dp) + helper(n - 1, 4, dp) + helper(n - 1, 7, dp);
        else // 9
            return dp[n][num] = helper(n - 1, 6, dp) + helper(n - 1, 8, dp) + helper(n - 1, 9, dp);
    }
    else if (num == 2 || num == 4 || num == 6)
    {
        if (num == 2)
            return dp[n][num] = helper(n - 1, 1, dp) + helper(n - 1, 3, dp) + helper(n - 1, 5, dp) + helper(n - 1, 2, dp);
        else if (num == 4)
            return dp[n][num] = helper(n - 1, 1, dp) + helper(n - 1, 5, dp) + helper(n - 1, 7, dp) + helper(n - 1, 4, dp);
        else // 6
            return dp[n][num] = helper(n - 1, 9, dp) + helper(n - 1, 3, dp) + helper(n - 1, 5, dp) + helper(n - 1, 6, dp);
    }
    else
    {
        if (num == 5)
            return dp[n][num] = helper(n - 1, 2, dp) + helper(n - 1, 4, dp) + helper(n - 1, 6, dp) + helper(n - 1, 8, dp) + helper(n - 1, 5, dp);
        else // 8
            return dp[n][num] = helper(n - 1, 5, dp) + helper(n - 1, 7, dp) + helper(n - 1, 9, dp) + helper(n - 1, 0, dp) + helper(n - 1, 8, dp);
    }
}

long long getCount(int n)
{
    if (n == 0)
        return 0;
    long long ans = 0;
    vector<vector<long long>> dp(n + 1, vector<long long>(10, -1));
    for (int start = 0; start <= 9; start++)
        ans += helper(n, start, dp);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << getCount(n) << "\n";
}