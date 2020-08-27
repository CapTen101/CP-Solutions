#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

void revinsert(stack<int> &s, int k)
{
    if (s.size() == 0)
    {
        s.push(k);
        return;
    }

    int temp = s.top();
    s.pop();

    revinsert(s, k);
    s.push(temp);

    return;
}

stack<int> rev(stack<int> s)
{
    if (s.size() == 1)
        return s;

    int temp = s.top();
    s.pop();
    revinsert(s, temp);

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);

    stack<int> s;
    s.push(9);
    s.push(7);
    s.push(0);
    s.push(3);
    s.push(10);
    s.push(3);
    s.push(2);
    s.push(7);

    rev(s);

    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}