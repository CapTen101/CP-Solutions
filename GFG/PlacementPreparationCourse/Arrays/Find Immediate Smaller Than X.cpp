// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// User function to complete
// arr[]: input array
// n: size of array
// k: find element smaller and closest to it.
int immediateSmaller(int arr[], int n, int x)
{
    // your code here

    int mindiff, temp = -1;

    mindiff = x - arr[0];

    for (int i = 0; i < n; i++)
    {
        if ((x - arr[i]) <= 0)
            continue;
        else
            temp = x - arr[i];

        mindiff = min(temp, mindiff);

        if (i == n - 1)
            return x - mindiff;
    }

    return -1;
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

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int x;
        cin >> x;

        cout << immediateSmaller(arr, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends