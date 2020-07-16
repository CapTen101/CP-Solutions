// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;

int firstRepeated(int *, int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << firstRepeated(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends

//User function template in C++

// arr : given array
// n : size of the array

int firstRepeated(int arr[], int n)
{
    //code here
    int minindex = -1;

    set<int> myset;

    for (int i = n - 1; i >= 0; i--)
    {
        if (myset.find(arr[i]) != myset.end())
            minindex = i;

        else
            myset.insert(arr[i]);
    }

    if (minindex != -1)
        return minindex + 1;
    else
        return -1;
}
