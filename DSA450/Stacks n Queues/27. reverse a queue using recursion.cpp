#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        queue<int> a = rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}

queue<int> rev(queue<int> q)
{
    // RECURSIVE WAY
    if (q.size() == 1)
        return q;

    int ele = q.front();
    q.pop();

    queue<int> reverse = rev(q);
    reverse.push(ele);

    return reverse;

    // ITERATIVE WAY:
    /*
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        int n = q.size();
        
        int i = n;
        while(i--){
            s.push(q.front());
            q.pop();
        }
        
        while(s.size()){
            q.push(s.top());
            s.pop();
        }
        
        return q;
    }
    */
}