// BEST ARTICLE EXPLAINING ALL APPROACHES:
// https://medium.com/swlh/solving-the-target-sum-problem-with-dynamic-programming-and-more-b76bd2a661f9

#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int findTargetSumWays(vector<int> &arr, int target)
{
    // TABULATION
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
        total += arr[i];

    if ((target > total) || (target + total) % 2)
        return 0;

    int sum = (target + total) / 2;
    int n = arr.size();

    int dp[n + 1][sum + 1];

    dp[0][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}