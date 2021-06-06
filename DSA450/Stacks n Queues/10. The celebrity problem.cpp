// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &m, int n)
    {
        int i, j, ans = -1;
        bool found = false;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (m[i][j] == 1)
                    break;
            }
            if (j == n)
            { // if no 1 found
                if (found)
                {
                    ans = -1;
                }
                else
                {
                    ans = i;
                    found = true;
                }
            }
        }

        return ans;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends