#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int majorityWins(int arr[], int n, int x, int y)
{
}

// { Driver Code Starts.

int main()
{

    int t;      //Testcases
    cin >> t;   // Input the testcases
    while (t--) //Until all testcases are exhausted
    {
        int n;                      //Size of array
        cin >> n;                   //Input the size
        int arr[n];                 //Declaring array of size n
        for (int i = 0; i < n; i++) // Running a loop to input all elements of arr
            cin >> arr[i];

        int x, y;                                   //declare x and y
        cin >> x >> y;                              // input x and y
        cout << majorityWins(arr, n, x, y) << endl; //calling the function that you complete
    }

    return 0;
} // } Driver Code Ends