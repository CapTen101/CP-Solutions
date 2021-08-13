#include <bits/stdc++.h>
using namespace std;

int knapsackMemoization(int wt[], int val[], int size, int capacity, vector<vector<int>> &dp)
{
    if (size == 0 || capacity == 0)
        return 0;

    // checking for the array if this value is already present or not
    if (dp[size][capacity] != -1)
        return dp[size][capacity];

    if (wt[size - 1] <= capacity)
        return dp[size][capacity] = max(val[size - 1] + knapsackMemoization(wt, val, size - 1, capacity - wt[size - 1], dp),
                                        knapsackMemoization(wt, val, size - 1, capacity, dp));

    else
        return dp[size][capacity] = knapsackMemoization(wt, val, size - 1, capacity, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);

    // take these input
    int wt[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[8] = {500, 30, 50, 344, 43, 93, 900, 3000};

    // take capacity as input
    int capacity = 100;
    int wt_size;
    int val_size;
    vector<vector<int>> dp(wt_size + 1, vector<int>(val_size + 1, -1));
    cout << knapsackMemoization(wt, val, 8, capacity, dp) << endl;
}