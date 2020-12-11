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

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int n, k;
        cin >> n >> k;

        string ans;

        for (int i = 1; i <= k; i++)
            ans += "a";

        if (n - k == 1)
        {
            ans += "c";
            cout << ans << endl;
            continue;
        }
        else if (n - k == 2)
        {
            ans += "cb";
            cout << ans << endl;
            continue;
        }
        else if (n - k == 3)
        {
            ans += "cba";
            cout << ans << endl;
            continue;
        }

        for (int i = k + 1; i <= n; i++)
        {
            if (ans[i - 1] == 'a')
                ans += "b";
            else if (ans[i - 1] == 'b')
                ans += "c";
            else if (ans[i - 1] == 'c')
                ans += "a";
        }

        cout << ans << endl;
    }
}