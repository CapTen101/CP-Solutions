#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

queue<int> interleave(queue<int> q)
{
    stack<int> a, b, ans;
    int n = q.size();
    int i = q.size() / 2;

    while (i--)
    {
        a.push(q.front());
        q.pop();
    }

    while (q.size())
    {
        b.push(q.front());
        q.pop();
    }

    while (a.size() and b.size())
    {
        ans.push(b.top());
        ans.push(a.top());
        b.pop();
        a.pop();
    }

    string s;
    s.append('0');

    while (ans.size())
    {
        q.push(ans.top());
        ans.pop();
    }

    return q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}