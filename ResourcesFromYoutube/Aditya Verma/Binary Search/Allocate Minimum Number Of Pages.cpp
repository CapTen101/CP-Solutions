/*
Problem Statement: https://www.geeksforgeeks.org/allocate-minimum-number-pages/
Question: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0
*/

#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

bool isvalid(int arr[], int n, int k, int mid)
{
    int stud = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            stud++;
            sum = arr[i];
        }
        if (stud > k)
            return false;
    }

    return true;
}

int alloc(int arr[], int n, int k)
{
    int s = *max_element(arr, arr + n);
    int e;

    for (int i = 0; i < n; i++)
        e += arr[i];

    int res = -1;

    if (n < k)
        return -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isvalid(arr, n, k, mid))
        {
            res = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n;
        cin >> n;

        int pg[n];

        for (int i = 0; i < n; i++)
        {
            cin >> pg[i];
        }

        int m;
        cin >> m;

        cout << alloc(pg, n, m);
    }
}