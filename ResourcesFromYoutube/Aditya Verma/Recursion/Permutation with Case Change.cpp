#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

void cap(string op, string ip)
{
    if (ip.empty())
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);          // we push the lower char as it is here
    op2.push_back(toupper(ip[0])); // we push the capital version of the char here
    ip.erase(ip.begin() + 0);

    cap(op1, ip);
    cap(op2, ip);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cap("", "gh");
}