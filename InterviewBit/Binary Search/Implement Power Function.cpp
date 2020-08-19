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

int power(int x, int n, int d)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1 % d;
    if (n == 1)
        return x % d;
    if (x < 0)
    {
        x += x;
        return x % d;
    }

    if (n % 2 != 0)
    {
        x *= x;
        n--;
    }

    return (power(x, n / 2, d) % d * (power(x, n / 2, d) % d)) % d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout << power(-1, 2, 20);
}