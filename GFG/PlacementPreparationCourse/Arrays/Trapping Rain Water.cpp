// **HARD** problem
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n)
{
    int water, l, r, lmax, rmax;

    l = 0;
    r = n - 1;
    water = 0;
    lmax = 0; // local max from left
    rmax = 0; // local max from right

    while (l <= r)
    {
        if (arr[l] < arr[r]) // check whosoever is greater among arr[l] or arr[r]
        {
            if (arr[l] > lmax)
            {
                lmax = arr[l];
            }
            else
            {
                water += (lmax - arr[l]);
            }
            l++;
        }
        else // if arr[l] is greater
        {
            if (arr[r] > rmax)
            {
                rmax = arr[r];
            }
            else
            {
                water += (rmax - arr[r]);
            }
            r--;
        }
    }

    return water;
}

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends