/*
Problem Statement: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
Question: https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int search(int **arr, int n, int m, int k)
{
    int i = 0;
    int j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (arr[i][j] == k)
        {
            // pair<int, int> p(i, j);
            // return p;

            // above two steps were for returning if questions demands pair of indexes.
            // here, we only need if present or not, so return 1 as follows::

            return 1;
        }
        else if (k < arr[i][j])
            j--;
        else if (k > arr[i][j])
            i++;
    }

    return 0; //element is not present.
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n, m, x;
        cin >> n >> m;
        int **arr;

        arr = new int *[n]; // assigned an array of rows from i = 0 to i = n - 1;

        for (int i = 0; i < n; i++)
            arr[i] = new int[m]; // assigned each row a coloumn array from j = 0 to j = m - 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        cin >> x;

        cout << search(arr, n, m, x) << endl;
    }
}