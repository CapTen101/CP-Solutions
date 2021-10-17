#include <bits/stdc++.h>
using namespace std;

int evalPostfix(string s)
{
    stack<int> required_stack;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            int x = required_stack.top();
            required_stack.pop();
            int y = required_stack.top();
            required_stack.pop();
            if (s[i] == '+')
                required_stack.push(y + x);
            else if (s[i] == '-')
                required_stack.push(y - x);
            else if (s[i] == '*')
                required_stack.push(y * x);
            else if (s[i] == '/')
                required_stack.push(y / x);
        }
        else
        {
            required_stack.push(s[i] - '0');
        }
    }
    return required_stack.top();
}

int main()
{
    cout<<evalPostfix("84-")<<endl;
    return 0;
}