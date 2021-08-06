#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long countWaysRecursive(int n, int k)
{
    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    // now from 3 fences and beyond...
    // follow same explanation as below function
    return (k - 1) * (countWaysRecursive(n - 1, k) + countWaysRecursive(n - 2, k));
}

long long countWays(int n, int k)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    long long same = k;                 // last two fence are of same colour
    long long different = k * (k - 1);  // last two fence are of different colour
    long long total = same + different; // total ways to paint the given fences

    for (int i = 3; i <= n; i++)
    {
        // now after including the next fence, keeping last two fence of same color means previous
        // fence different value and adding the same colour by 1 ways.
        same = (different * 1) % mod;

        // now after including the next fence, keeping last two fence of different color means previous
        // fence total value and adding the rest of the k-1 colours by k-1 ways
        // hence multiply by k-1
        different = ((total % mod) * ((k - 1) % mod)) % mod;

        // collecting the total number of ways
        total = (same + different) % mod;
    }

    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}