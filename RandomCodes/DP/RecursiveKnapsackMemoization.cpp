#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int t[9][101];
int knapsackMemoization(int wt[], int val[], int size, int capacity)
{
    if (size == 0 || capacity == 0)
        return 0;

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