#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helperMem(int n, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        if (wt[n - 1] <= W)
            return dp[n][W] = max(helperMem(n - 1, W, val, wt, dp), (val[n - 1] + helperMem(n, W - wt[n - 1], val, wt, dp)));
        else
            return dp[n][W] = helperMem(n - 1, W, val, wt, dp);
    }

    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return helperMem(n, W, val, wt, dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}