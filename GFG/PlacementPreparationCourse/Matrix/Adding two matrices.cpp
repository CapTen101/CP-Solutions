

for (int j = 0; j < A[0].size(); j++)

// { Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> sumMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
    {
        if (A.size() != B.size())
        {
            vector<vector<int>> D;
            return D;
        }
        if (A[0].size() != B[0].size())
        {
            vector<vector<int>> E;
            return E;
        }

        vector<vector<int>> C(A.size());
        // code here
        for (int i = 0; i < A.size(); i++)
        {
            C[i].assign(A[0].size(), 0);
            for (int j = 0; j < A[0].size(); j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        return C;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> A(row);
        for (int i = 0; i < row; i++)
        {
            A[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> A[i][j];
            }
        }
        cin >> row >> col;
        vector<vector<int>> B(row);
        for (int i = 0; i < row; i++)
        {
            B[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> B[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> result = ob.sumMatrix(A, B);
        if (result.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout << result[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends