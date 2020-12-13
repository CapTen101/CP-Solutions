#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define FOR(i, start, end) for (int i = start; i < end; i++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
// #define start \
//     int t;    \
//     cin >> t; \
//     while (t--)
// const ll mod = 1000000007;

//-- NOT DONE --

int maxCoins(vector<int> &nums)
{
    vector<int> a(nums.size() + 2, 1);
    for (int i = 0; i < nums.size(); i++)
        a[i + 1] = nums[i];
    int n = a.size();

    vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j]: the maximum coins of (i, j), not of [i, j] or (i, j] or [i, j)
    for (int len = 2; len < n; len++)
    {
        for (int l = 0; l < n - len; l++)
        {
            int r = l + len, tmp = INT_MIN;
            for (int k = l + 1; k < r; k++)
                tmp = max(tmp, a[l] * a[k] * a[r] + dp[l][k] + dp[k][r]);
            dp[l][r] = tmp;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
}