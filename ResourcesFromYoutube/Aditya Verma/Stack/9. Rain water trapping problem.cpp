#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trappingWater(int a[], int n)
    {
        // - for every element a[i] in the array, find max element on the right (mxr) and similarly on left(mxl)
        // - then simply find sum of following: (min(mxr[i], mxrl[i]) - arr[i]) for every a[i]
        // THAT'S IT!

        int mxr[n];
        mxr[n - 1] = a[n - 1];
        int mxl[n];
        mxl[0] = a[0];

        // mxr -> start from right
        for (int i = n - 2; i >= 0; i--)
        {
            mxr[i] = max(mxr[i + 1], a[i]);
        }

        // mxl - start from left
        for (int i = 1; i < n; i++)
        {
            mxl[i] = max(mxl[i - 1], a[i]);
        }

        int water[n];
        int totalwater = 0;

        for (int i = 0; i < n; i++)
        {
            water[i] = min(mxr[i], mxl[i]) - a[i];
            totalwater += max(totalwater, water[i]);
        }

        return totalwater;
    }
};

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends