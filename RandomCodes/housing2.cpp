#include <bits/stdc++.h>
using namespace std;

int knapsackMemoization(vector<int> wt, vector<int> val, int size, int capacity, vector<vector<int>> &dp)
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

int maxBenefit(int input1, int input2[], int input3[], int input4)
{
    int n = input1;
    int W = input4;
    vector<int> wt(input2, input2 + n);
    vector<int> val(input3, input3 + n);

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsackMemoization(wt, val, n, W, dp);
}