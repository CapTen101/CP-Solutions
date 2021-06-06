// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int p[], int n)
    {
        // It's basically "Next Greater element on the left (NGL)" problem
        stack<int> s;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                s.push(i);
                ans.push_back(1);
            }
            else if (s.size() and p[s.top()] > p[i])
            {
                ans.push_back(i - s.top());
                s.push(i);
            }
            else if (s.size() and p[s.top()] <= p[i])
            {
                while (s.size() and p[s.top()] <= p[i])
                    s.pop();

                // if stack is empty
                if (!s.size())
                {
                    ans.push_back(i + 1);
                    s.push(i);
                    continue;
                }
                else
                {
                    // if a greater element was found on left
                    ans.push_back(i - s.top());
                    s.push(i);
                    continue;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}