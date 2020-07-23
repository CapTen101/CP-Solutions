/*
Problem Statement: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

// Implemented LINEAR SEARCH algo
long pivotind(long int arr[], long int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
    {
        if (arr[0] > arr[1])
            return 1;
        else
            return 0;
    }

    for (long i = 0; i < n; i++)
    {
        if (arr[0] < arr[n - 1])
            return 0;
        if (i > 0 && arr[i] <= arr[(i + 1) % n] && arr[i] < arr[i - 1])
            return i;
    }

    return -1;
}

long bin_search_ITERATIVE(long A[], long left, long right, long k)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == k)
        {
            return mid;
        }

        else if (k > A[mid])
        {
            left = mid + 1;
        }

        else if (k < A[mid])
        {
            right = mid - 1;
        }
    }

    return -1;
}

long search(long arr[], long n, long k)
{
    long minindex = pivotind(arr, n);
    long index = -1;

    if (k < arr[minindex])
    {
        index = bin_search_ITERATIVE(arr, 0, minindex - 1, k);
    }

    long firsthalf = bin_search_ITERATIVE(arr, 0, minindex - 1, k);
    long secondhalf = bin_search_ITERATIVE(arr, minindex + 1, n - 1, k);

    if (firsthalf != -1)
        return firsthalf;
    else if (secondhalf != -1)
        return secondhalf;
    else
        return -1;

    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        long n, k;
        cin >> n;
        long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cin >> k;

        cout << search(arr, n, k) << endl;
    }
}