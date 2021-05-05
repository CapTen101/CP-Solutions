// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countSquares(int N)
    {
        // code here
        if (N == 0 || N == 1)
            return 0;

        int root = sqrt(N);

        if (root * root == N)
            return root - 1;

        long long root1 = sqrt(N);
        return (int)root1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} // } Driver Code Ends