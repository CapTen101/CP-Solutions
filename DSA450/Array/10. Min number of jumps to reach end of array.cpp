#include <bits/stdc++.h>
using namespace std;

int helper(int a[], int pos, int n)
{
    if (n <= 0)
        return 0;
}

class Solution
{
public:
    int minJumps(int a[], int n)
    {
        // Your code here
        int jc = 0;
        int pos = 0;

        while (pos < n)
        {
        }

        return jc;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}