#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

class Solution
{
public:
#define mod 1000000007
    long long helper(int n, int k, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        if (dp[n] != -1)
            return dp[n] % mod;

        // diff + same
        return dp[n] = ((k - 1) % mod * (helper(n - 2, k, dp) % mod + helper(n - 1, k, dp) % mod) % mod) % mod;
    }

    long long countWays(int n, int k)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        vector<int> dp(n + 1, -1);
        return helper(n, k, dp);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
}