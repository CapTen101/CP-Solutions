#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

void permute(string op, string ip)
{
    if (ip.empty())
    {
        cout << "(" << op << ")";
        return;
    }

    string op1 = op;    // if we include space
    string op2 = op;    // if we don't include space
    op1.push_back(' '); // this is the included space
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0); // and now remove the first char of the input

    permute(op1, ip);
    permute(op2, ip);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    start
    {
        string s;
        cin >> s;
        string op;
        op.push_back(s[0]);
        s.erase(s.begin() + 0);
        permute(op, s);
        cout << endl;
    }
}