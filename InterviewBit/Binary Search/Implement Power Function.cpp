#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

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
        x += d;
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