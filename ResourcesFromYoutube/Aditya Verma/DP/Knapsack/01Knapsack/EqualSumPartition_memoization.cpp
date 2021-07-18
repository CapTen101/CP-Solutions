#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subsetsum(int n, int arr[], int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        else if (n == 0 and sum != 0)
            return false;

        if (dp[n][sum] != -1)
        {
            return bool(dp[n][sum]);
        }

        if (arr[n - 1] <= sum)
        {
            return bool(dp[n][sum] = subsetsum(n - 1, arr, sum - arr[n - 1], dp) || subsetsum(n - 1, arr, sum, dp));
        }
        else
            return bool(dp[n][sum] = subsetsum(n - 1, arr, sum, dp));
    }

    int equalPartition(int n, int arr[])
    {
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }

        int half = total / 2;

        if (total % 2)
        {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(half + 1, -1));

        return subsetsum(n, arr, half, dp);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}