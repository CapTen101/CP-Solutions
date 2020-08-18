/*
Problem Statement link: https://www.geeksforgeeks.org/find-element-bitonic-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int peak(int arr[], int n)
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

int bin_search_ITERATIVE(int A[], int left, int right, int k)
{
    int n = right + 1;

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

int binary_dec(int a[], int leftIndex, int rightIndex, int value)
{
    while (leftIndex < rightIndex)
    {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        if (value == a[mid])
        {
            return mid;
        }
        else if (value > a[mid])
        {
            rightIndex = mid - 1;
        }
        else if (value < a[mid])
        {
            leftIndex = mid + 1;
        }
    }

    return -1;
}

int search_bitonic(int arr[], int n, int k)
{
    int peakelement = peak(arr, n);
    int l = 0;
    int r = n - 1;

    if (k == arr[peakelement])
        return peakelement;

    int firsthalf = bin_search_ITERATIVE(arr, 0, peakelement - 1, k);
    int secondhalf = binary_dec(arr, peakelement, n - 1, k);

    if (firsthalf != -1)
        return firsthalf;
    else if (secondhalf != -1)
        return secondhalf;
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int x;
        cin >> x;

        cout << search_bitonic(arr, n, x) << endl;
    }
}