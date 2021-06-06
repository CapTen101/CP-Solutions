// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        cout << ch;
        cout << endl;
    }
    return 0;
}

char *reverse(char *str, int len)
{
    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }

    char stn[len];

    for (int i = 0; i < len; i++)
    {
        str[i] = s.top();
        s.pop();
    }

    return str;
}