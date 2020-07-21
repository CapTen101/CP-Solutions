// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find missing integer in array
// arr: input array
// n: size of array
int findMissing(int arr[], int n)
{
    // Your code here
    set<int> s;
    bool found;
    int num = 1;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    do
    {
        if (s.find(num) != s.end())
        {
            found = 1;
        }
        else
        {
            found = 0;
            return num;
        }

        num++;

    } while (found);
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
            cin >> arr[i];

        cout << findMissing(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends