/* Problem Statement
https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int bin_firstoccurence(int arr[], int l, int r, int k)
{
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (k == arr[mid])
        {
            ans = mid;
            r = mid - 1;
            continue;
        }
        else if (k < arr[mid])
        {
            r = mid - 1;
        }
        else if (k > arr[mid])
        {
            l = mid + 1;
        }
    }

    return ans;
}

int bin_lastoccurence(int arr[], int l, int r, int k)
{
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (k == arr[mid])
        {
            ans = mid;
            l = mid + 1;
            continue;
        }
        else if (k < arr[mid])
        {
            r = mid - 1;
        }
        else if (k > arr[mid])
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n, x;
        cin >> n >> x;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int first = bin_firstoccurence(arr, 0, n - 1, x);
        int last = bin_lastoccurence(arr, 0, n - 1, x);

        if (first == -1 && last == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << first << " " << last << endl;
        }
    }
}