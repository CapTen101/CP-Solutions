#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    if (n == 1)
        return 1;

    vector<int> dp(n);
    dp[0] = 1;

    int exp_2 = 0, exp_3 = 0, exp_5 = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[exp_2] * 2, min(dp[exp_3] * 3, dp[exp_5] * 5));

        if (dp[i] == dp[exp_2] * 2)
            exp_2++;
        if (dp[i] == dp[exp_3] * 3)
            exp_3++;
        if (dp[i] == dp[exp_5] * 5)
            exp_5++;
    }

    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}