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

int factorial(int n)
{
    // base case
    if (n == 1)
        return 1;

    return n * factorial(n - 1); // first is induction and second is hypothesis
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout << factorial(5);
}