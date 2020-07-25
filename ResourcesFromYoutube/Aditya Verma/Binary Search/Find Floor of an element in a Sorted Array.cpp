/* 
Problem Statement: https://www.geeksforgeeks.org/floor-in-a-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int search(long long arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n, x;
        cin >> n >> x;

        long long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << search(arr, n, x);
    }
}