// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> NSL(long long a[], int n)
{
    stack<int> s;
    vector<int> v;
    int fake_idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (!s.size())
        {
            v.push_back(fake_idx);
            s.push(i);
        }
        else if (s.size() and a[s.top()] < a[i])
        {
            v.push_back(s.top());
            s.push(i);
        }
        else if (s.size() and a[s.top()] >= a[i])
        {
            while (s.size() and a[s.top()] >= a[i])
                s.pop();

            if (!s.size())
            {
                v.push_back(fake_idx);
                s.push(i);
            }
            else
            {
                v.push_back(s.top());
                s.push(i);
            }
        }
    }

    return v;
}

vector<int> NSR(long long a[], int n)
{
    stack<int> s;
    vector<int> v;
    int fake_idx = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (!s.size())
        {
            v.push_back(fake_idx);
            s.push(i);
        }
        else if (s.size() and a[s.top()] < a[i])
        {
            v.push_back(s.top());
            s.push(i);
        }
        else if (s.size() and a[s.top()] >= a[i])
        {
            while (s.size() and a[s.top()] >= a[i])
                s.pop();

            if (!s.size())
            {
                v.push_back(fake_idx);
                s.push(i);
            }
            else
            {
                v.push_back(s.top());
                s.push(i);
            }
        }
    }

    reverse(v.begin(), v.end());

    return v;
}

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    {
        vector<int> left = NSL(a, n);
        vector<int> right = NSR(a, n);

        long long max_area = 0;
        for (int i = 0; i < n; i++)
        {
            max_area = max(max_area, (right[i] - left[i] - 1) * a[i]);
        }

        return max_area;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends