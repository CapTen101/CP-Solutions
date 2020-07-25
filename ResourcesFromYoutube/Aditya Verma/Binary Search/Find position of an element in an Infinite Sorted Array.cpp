#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

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

int search(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;

    while (arr[r] < k)
    {
        l = r;
        r *= 2; // can take any no. other than 2
    }

    return bin_search_ITERATIVE(arr, l, r, k);
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

        cout << search(arr, n, x) << endl;
    }
}