// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> a, int n)
    {

        if (n == 1)
        {
            vector<long long> v(1);
            v[0] = -1;
            return v;
        }
        // Your code here
        stack<long long> s;
        vector<long long> ans;
        for (long long i = a.size() - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else if (!s.empty() && s.top() > a[i])
            {
                ans.push_back(s.top());
            }
            else if (!s.empty() && s.top() <= a[i])
            {
                while (!s.empty() and s.top() <= a[i])
                    s.pop();

                // now check again
                // if stack becomes empty
                if (s.empty())
                {
                    ans.push_back(-1);
                }
                else // if greater element is found
                {
                    ans.push_back(s.top());
                }
            }

            s.push(a[i]);
        }

        int siz = ans.size();
        for (int i = 0; i < siz / 2; i++)
        {
            swap(ans[i], ans[n - i - 1]);
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