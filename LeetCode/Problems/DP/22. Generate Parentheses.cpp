#include <bits/stdc++.h>
using namespace std;

void helper(vector<string> &v, string s, int o, int c)
{
    if (o == 0 and c == 0)
    {
        v.push_back(s);
        return;
    }

    if (c > 0)
        helper(v, s + ')', o, c - 1);
    if (o > 0)
        helper(v, s + '(', o - 1, c + 1);
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    helper(v, "", n, 0);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}