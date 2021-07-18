#include <bits/stdc++.h>
using namespace std;

int t[9][101];
int TabulationKnapsack(int wt[], int val[], int size, int capacity)
{
    // initialization
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    // computation
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (wt[i - 1] <= j) // i is the size and j is the capacity for this sub-problem under consideration (i,j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[size][capacity];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int wt[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[8] = {500, 30, 50, 344, 43, 93, 900, 3000};
    int capacity = 100;
    cout << TabulationKnapsack(wt, val, 8, capacity) << endl;
}