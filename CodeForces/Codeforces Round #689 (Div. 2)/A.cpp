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

        string ans = "abc";

        FOR(i, 0, n)
        {
            cout << ans[i % 3];
        }
        cout << endl;
    }
}