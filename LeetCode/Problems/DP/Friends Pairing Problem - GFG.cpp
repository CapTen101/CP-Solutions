#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int helper(int n, vector<int> &dp)
{
    if (dp[n] != -1)
        return dp[n];

    if (n == 1)
        return dp[n] = 1;
    if (n == 2)
        return dp[n] = 2;

    return dp[n] = (helper(n - 1, dp) % mod + ((helper(n - 2, dp) % mod) * ((n - 1) % mod)) % mod) % mod;
}

int countFriendsPairings(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countFriendsPairings(n);
    }
}