// Link: https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3554/

#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int kthFactor(int n, int k)
{
    int count = 1;
    vector<int> factors;
    factors.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            factors.push_back(i);
    }

    if (factors.size() < k)
        return -1;
    else
    {
        return factors[k - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}