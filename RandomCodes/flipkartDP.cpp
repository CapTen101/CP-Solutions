#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll helper(vector<ll> &num, ll n, ll W, vector<vector<ll>> &dp)
{
    if (W < 0)
        return 0;
    if (n < 0 && W > 0)
        return 0;
    if (W == 0 && n >= 0)
        return 1;

    if (dp[n][W] != -1)
        return dp[n][W];

    return dp[n][W] = helper(num, n - 1, W - num[n - 1], dp) + helper(num, n - 1, W, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> num(2);
    num[0] = 1;
    num[1] = 1;

    for (ll i = 2; i < n; i++)
    {
        ll x = (num[i - 1] + num[i - 2]);
        if (x <= n)
            num.push_back(x);
        else
            break;
    }

    for (ll i = 0; i < num.size() - 1; i++)
    {
        num[i] = num[i + 1];
    }

    num.pop_back();

    vector<vector<ll>> dp(num.size() + 1, vector<ll>(n + 1, -1));

    cout << helper(num, num.size(), n, dp) << endl;
}