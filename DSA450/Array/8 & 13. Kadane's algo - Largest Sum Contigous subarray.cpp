for (int i = 1; i < n; i++)

// { Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n)
    {

        // Your code here

        int current_sum = a[0];
        int overall_sum = a[0];

        for (int i = 1; i < n; i++)
        {
            current_sum = max(a[i], current_sum + a[i]);
            overall_sum = max(overall_sum, current_sum);
        }

        return overall_sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends