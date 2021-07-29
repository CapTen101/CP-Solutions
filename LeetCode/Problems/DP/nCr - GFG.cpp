#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int fact(int n)
{
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = (factorial % mod * i % mod) % mod;
    }

    return factorial;
}

int fact_dp(int n)
{
    if (n == 0)
        return 1;
    return n * fact_dp(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fact(5);
}