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
    int res = -1;

    if (arr[r] < x)
        return r;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] < x)
        {
            res = mid;
            l = mid + 1;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
    }

    return -1;
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

        cout << search(arr, n, x) << endl;
    }
}