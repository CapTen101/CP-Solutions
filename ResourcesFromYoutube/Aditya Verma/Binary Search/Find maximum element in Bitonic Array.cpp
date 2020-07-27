/*
Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing
sequence of integers followed immediately by a decreasing sequence of integers.

Problem Statement: https://www.includehelp.com/icp/maximum-value-in-a-bitonic-array.aspx
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int bitonic(int arr[], int n) // literally he same as the Peak Element question because the bitonic array has a single peak element.
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (mid > 0 && mid < n - 1) // excluding the first and last element. we'll handle them a lil' later.
        {
            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
                return mid; // this is the peak element

            else if (arr[mid - 1] > arr[mid])
                r = mid - 1;
            else if (arr[mid + 1] > arr[mid])
                l = mid + 1;
        }
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
                return 0;
            else
                return 1;
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
                return n - 1;
            else
                return n - 2;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
}