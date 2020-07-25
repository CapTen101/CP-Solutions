/* 
Problem Statement: https://www.geeksforgeeks.org/search-almost-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int search(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (k == arr[mid])
            return mid;
        else if (mid >= l && k == arr[mid + 1])
            return mid + 1;
        else if (mid <= r && k == arr[mid - 1])
            return mid - 1;

        if (k > arr[mid])
            l = mid + 2;
        else if (k < arr[mid])
            r = mid - 2;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
}