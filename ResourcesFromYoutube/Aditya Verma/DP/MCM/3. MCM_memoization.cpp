#include <bits/stdc++.h>
using namespace std;

// cost of multiplication = rows of 1st [][] + common_columns_btw_2_matrices + column of 2nd [][]
// putting i,j into the array. i = 1 and j = n-1 since one of the dimension involves arr[i-1] and hence will start from 0.

int solve(int arr[], int i, int j, vector<vector<int>> &dp)
{
    // i==j is also not possible since we need two indices to define the dimension of a matrix
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        // the last term is the cost of multiplying the two obtained temp answers
        int temp_ans = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp_ans);
    }

    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << solve(arr, 1, n - 1, dp);
}