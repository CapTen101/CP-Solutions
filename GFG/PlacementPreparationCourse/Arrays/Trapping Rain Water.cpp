// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n)
{

    // Your code here
    int maxh = arr[0], water = 0;

    for (int i = 0; i < n; i++)
    {
        maxh = max(maxh, arr[i]);

        if (arr[i] <= maxh)
        {
            water += (maxh - arr[i]);
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