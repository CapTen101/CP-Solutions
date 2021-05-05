// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        // MOORE's VOTING ALGO

        int count = 1;
        int ele = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] == ele)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    ele = a[i];
                    count++;
                }
            }
        }

        count = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == ele)
                count++;
        }

        return ((count > n / 2) ? ele : -1);
    }
};

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
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends