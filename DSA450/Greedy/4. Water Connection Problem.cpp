// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
} // } Driver Code Ends