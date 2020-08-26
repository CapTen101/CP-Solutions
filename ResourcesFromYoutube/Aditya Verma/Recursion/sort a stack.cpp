#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

// CODE IS EXACTLY SAME FOR SORTING A STACK BECAUSE WE CAN TAKE THE END OF ARRAY AS THE OPEN LID OF A STACK.
// THAT'S IT!

void insert(stack<int> &s, int k)
{
    if (s.size() == 0 || s.top() <= k)
    {
        s.push(k);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s, k);
    s.push(temp);
}

void sort(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();

    sort(s);
    insert(s, temp);
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

    sort(s);

    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}