/*
Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array
is sorted, we don’t know if it’s sorted in ascending or descending order.
*/

#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int binary_inc(int a[], int leftIndex, int rightIndex, int value)
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
            leftIndex = mid + 1;
        }
        else if (value < a[mid])
        {
            rightIndex = mid - 1;
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

int bin_agnotic_search(int arr[], int leftIndex, int rightIndex, int value)
{
againcheck:

    int i = 0;
    bool dec = 0, inc = 0;

    if (arr[i + 1] > arr[i])
    {
        inc = 1;
    }
    else if (arr[i + 1] < arr[i])
    {
        dec = 1;
    }
    else
    {
        i++;
        goto againcheck;
    }

    if (inc)
    {
        return binary_inc(arr, leftIndex, rightIndex, value);
    }
    else
    {
        return binary_dec(arr, leftIndex, rightIndex, value);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}