// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // it's written smaller element on right, so check right array for greater/smaller element
    vector<long long> nextLargerElement(vector<long long> a, int n)
    {
        // Your code here
        stack<long long> s;
        vector<long long> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                ans.push_back(-1);
                s.push(a[i]);
            }
            else if (s.size() and s.top() > a[i])
            {
                ans.push_back(s.top());
                s.push(a[i]);
            }
            else if (s.size() and s.top() <= a[i])
            {
                while (s.top() <= a[i] && s.size())
                    s.pop();

                // now check again
                // if stack becomes empty
                if (!s.size())
                {
                    ans.push_back(-1);
                    s.push(a[i]);
                    continue;
                }
                else // if greater element is found
                {
                    ans.push_back(s.top());
                    s.push(a[i]);
                    continue;
                }
            }
        }

        reverse(ans.begin(), ans.end());

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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends