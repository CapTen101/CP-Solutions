#include <bits/stdc++.h>
using namespace std;

int ones(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

vector<int> countBits(int n)
{
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = ones(i);
        // can also do __builtin_popcount(i)
        // 4 imp __builtin functions:
        // - __builtin_parity(i) -> returns 0 for even parity and 1 for odd parity. {parity is }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}