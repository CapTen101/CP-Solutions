#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

// here the extended input ouput method will be used.
// this method simply means that instead of in  and op having same data types, they'll now have different data-types.
void print(int open, int close, string op, vector<string> &v)
{
    //base condition:
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }

    // till open is not zero we have the option of placing an open '(' bracket
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        print(open - 1, close, op1, v);
    }

    // A close bracket can only be placed only when close > open
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        print(open, close - 1, op2, v);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> ans;

    // we already need to push an open bracket
    // to output to even begin the balancing task since with a close bracket we  can't do  anything
    int open = n;
    int close = n;
    string output = "";
    output.push_back('('); // since we need an open bracket to start the balancing process.
}