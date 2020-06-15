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
int TabulationKnapsack(int wt[], int val[], int size, int capacity)
{
    loop(int, i, 0, size + 1)
    {
        loop(int, j, 0, capacity + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    loop(int, i, 1, size + 1)
    {
        loop(int, j, 1, capacity + 1)
        {
            if (wt[i - 1] <= capacity)
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