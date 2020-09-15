#include <bits/stdc++.h>
using namespace std;

int t[9][101]; // two variable inputs will be the rows and coloumn of this dp matrix.

// memset sets the value of the 2-d array in one shot as t[n+1][capacity+1]
int knapsackMemoization(int wt[], int val[], int size, int capacity)
{
    if (size == 0 || capacity == 0)
        return 0;

    // checking for the array if this value is already present or not
    if (t[size][capacity] != -1)
        return t[size][capacity];

    if (wt[size - 1] <= capacity)
        return t[size][capacity] = max(val[size - 1] + knapsackMemoization(wt, val, size - 1, capacity - wt[size - 1]), knapsackMemoization(wt, val, size - 1, capacity));

    else
        return t[size][capacity] = knapsackMemoization(wt, val, size - 1, capacity);
}

int main()
{
    ios_base::sync_with_stdio(false);

    memset(t, -1, sizeof(t));
    int wt[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[8] = {500, 30, 50, 344, 43, 93, 900, 3000};
    int capacity = 100;
    cout << knapsackMemoization(wt, val, 8, capacity) << endl;
}