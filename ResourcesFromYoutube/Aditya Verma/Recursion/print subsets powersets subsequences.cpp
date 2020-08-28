#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

void print(string ip, string op)
{
    // base condition
    if (ip.empty())
    {
        cout << op << endl;
        return;
    }

    // we'll do this by ip/op method
    // first of all output1 will be as it is since we take negative decision for the next input character
    string op1 = op;

    // second input is also intialised to given output and later first char of input is added since we take a
    // positive decision for the next incoming character from the input
    string op2 = op;

    // here the positive decision is made
    op2.push_back(ip[0]);

    // and then we'll erase the
    ip.erase(ip.begin());

    // now recurse for both these outputs one by one along with new input
    print(ip, op1);
    print(ip, op2);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    print("hdut", "");
}