/* 
Given a sorted array, find the element in the array which has minimum difference with the given number.

This question tells us how we can calculate the floor and ceil from a different approach!!
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

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == k)
        {
            return arr[mid];
        }

        if (k > arr[mid])
        {
            l = mid + 1;
        }
        else if (k < arr[mid])
        {
            r = mid - 1;
        }
    }

    int first = abs(arr[l] - k);
    int second = abs(arr[r] - k);

    if (first < second)
        return arr[l];
    else
        return arr[r];
}

int main()
{
    ios_base::sync_with_stdio(false);
}
