#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int size, int capacity)
{
    if (size == 0 || capacity == 0) // smallest valid input of n and w
        return 0;

    if (wt[size - 1] <= capacity)
        return max(val[size - 1] + knapsack(wt, val, size - 1, capacity - wt[size - 1]), // if we include the element
                   knapsack(wt, val, size - 1, capacity));                               // if we DON'T include the element
                                                                                         // and take the maximum

    else
        return knapsack(wt, val, size - 1, capacity); // if this element is already larger than the capacity
}

int main()
{
    ios_base::sync_with_stdio(false);

    int wt[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[8] = {500, 30, 50, 344, 43, 93, 900, 3000};
    int capacity = 100;
    cout << knapsack(wt, val, 8, capacity);
}