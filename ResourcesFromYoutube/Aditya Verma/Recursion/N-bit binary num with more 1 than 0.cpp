#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

void print(string op, int n, int one, int zero)
{
    if (n == 0)
    {
        cout << op << " ";
        return;
    }

    //choice for adding 1 is always there. choice for zero is limited in some cases.
    string op1 = op;
    op1.push_back('1');
    print(op1, n - 1, one + 1, zero);

    // here we'll add a zero in the string
    if (one > zero)
    {
        string op2 = op;
        op2.push_back('0');
        print(op2, n - 1, one, zero + 1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n;
        cin >> n;

        int one = 0;
        int zero = 0;

        string op = "";
        print(op, n, one, zero);
        cout << endl;
    }
}