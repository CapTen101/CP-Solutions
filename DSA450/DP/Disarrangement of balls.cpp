#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long int disarrange(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;

        vector<long long int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.disarrange(N) << "\n";
    }
    return 0;
}