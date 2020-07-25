#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int bin_firstoccurence(int arr[], int l, int r, int k)
{
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (k == arr[mid])
        {
            ans = mid;
            r = mid - 1;
            continue;
        }
        else if (k < arr[mid])
        {
            r = mid - 1;
        }
        else if (k > arr[mid])
        {
            l = mid + 1;
        }
    }

    return ans;
}

int search(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;

    while (arr[r] != 1)
    {
        l = r;
        r *= 2; // can take any no. other than 2
    }

    return bin_firstoccurence(arr, l, r, k);
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