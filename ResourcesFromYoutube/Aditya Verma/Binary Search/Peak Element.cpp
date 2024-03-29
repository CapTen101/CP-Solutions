#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

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

int main()
{
    ios_base::sync_with_stdio(false);
}