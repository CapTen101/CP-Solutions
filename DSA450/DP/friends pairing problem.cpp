#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define mod 1000000007
    long long int helper(int n, vector<long long int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];

        if (n == 1)
            return dp[n] = 1;
        if (n == 2)
            return dp[n] = 2;
        if (n == 3)
            return dp[n] = 4;

        return dp[n] = (helper(n - 1, dp) % mod + ((n - 1) % mod * helper(n - 2, dp) % mod) % mod) % mod;
    }

    int countFriendsPairings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 4;

        vector<long long int> dp(n + 1, -1);
        return helper(n, dp);
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}