// Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> a, int n)
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

vector<int> NSR(vector<int> a, int n)
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

int MAH(vector<int> a, int n)
{
    vector<int> left = NSL(a, n);
    vector<int> right = NSR(a, n);

    int max_area = 0;
    for (int i = 0; i < n; i++)
    {
        max_area = max(max_area, (right[i] - left[i] - 1) * a[i]);
    }

    return max_area;
}

#define MAX 1000
class Solution
{
public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        vector<int> v;
        int max_rect = -1;
        for (int i = 0; i < m; i++)
        {
            v.push_back(M[0][i]);
        }

        max_rect = MAH(v, v.size());

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                {
                    v[j] = 0;
                }
                else
                    v[j] += M[i][j];
            }
            max_rect = max(max_rect, MAH(v, v.size()));
        }

        return max_rect;
    }
};

int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}