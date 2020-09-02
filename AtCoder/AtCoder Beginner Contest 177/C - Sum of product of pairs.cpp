#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

const long long mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum %= mod;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum -= arr[i];

        if (sum < 0)
            sum += mod;

        ans += sum * arr[i];
        ans %= mod;
    }

    cout << ans << endl;
}