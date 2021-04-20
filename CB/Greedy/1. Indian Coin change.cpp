#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int coin_change(vector<int> coins, int money)
{
    int ans = 0;
    while (money > 0)
    {
        int idx = upper_bound(coins.begin(), coins.end(), money) - coins.begin() - 1; // gives index of nmber just greater than money
        money -= coins[idx];
        ans++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    cout << "number of coins = " << coin_change(coins, n) << endl;
}