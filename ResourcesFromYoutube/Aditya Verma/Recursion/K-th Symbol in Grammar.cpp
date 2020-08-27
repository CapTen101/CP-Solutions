#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;

    int mid = pow(2, n - 1) / 2;
    if (k <= mid)
    {
        return kthGrammar(n - 1, k);
    }
    else
    {
        return !kthGrammar(n - 1, k - mid);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}