/*
Problem Statement: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int binSearch(vector<int> &arr, int k, int l, int h)
{
    int n = arr.size();

    while (l <= h)
    {

        int mid = l + ((h - l) / 2);

        if (arr[mid] == k)
            return mid;
        else if (k > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1;
}

int pivot_index(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return 0;

    if (n == 2)
    {
        return arr[0] > arr[1] ? 1 : 0;
    }

    if (arr[0] < arr[n - 1])
        return 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[(i + 1) % n] and arr[i] < arr[i - 1])
            return i;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivotidx = pivot_index(nums);
    int n = nums.size();

    int firstHalf = binSearch(nums, target, 0, pivotidx - 1);
    if (firstHalf != -1)
        return firstHalf;

    int secondHalf = binSearch(nums, target, pivotidx, n - 1);
    if (secondHalf != -1)
        return secondHalf;

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        long n, k;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cin >> k;

        cout << search(arr, k) << endl;
    }
}