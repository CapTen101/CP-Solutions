/* Question:
Given an array of integers, find the closest (not considering distance,but value)
smaller on left of every element. If an element has no lesser element on the left side, print -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // just exact reverse of previous question.
    // it's written smaller element on left, so check left array for greater/smaller element
    vector<long long> nextSmallestToLeft(vector<long long> a, int n)
    {
        stack<long long> s;
        vector<long long> ans;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                ans.push_back(-1);
                s.push(a[i]);
            }
            else if (s.size() and s.top() < a[i])
            {
                ans.push_back(s.top());
                s.push(a[i]);
            }
            else if (s.size() and s.top() >= a[i])
            {
                while (s.top() >= a[i] && s.size())
                    s.pop();

                // now check again
                // if stack becomes empty
                if (!s.size())
                {
                    ans.push_back(-1);
                    s.push(a[i]);
                    continue;
                }
                else // if smaller element is found
                {
                    ans.push_back(s.top());
                    s.push(a[i]);
                    continue;
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}