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

bool isvalid(long arr[], long n, long k, long mid)
{
    long long stud = 1;
    long long sum = 0;

    for (long i = 0; i < n; i++)
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

long long alloc(long arr[], long n, long k)
{
    long long s = *max_element(arr, arr + n);
    long long e = 0;

    for (long i = 0; i < n; i++)
        e += arr[i];

    long res = -1;

    if (n < k)
        return -1;

    while (s <= e)
    {
        long mid = s + (e - s) / 2;

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
        long n;
        cin >> n;

        long pg[n];

        for (int i = 0; i < n; i++)
        {
            cin >> pg[i];
        }

        long m;
        cin >> m;

        cout << alloc(pg, n, m) << endl;
    }
}