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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        int n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        if (b >= 0)
        {
            cout << n * (a + b) << endl;
            continue;
        }
        else
        {
            vector<int> m;

            int sum = 0, count = 0, total = 0;
            int num = (s[0] == '0') ? '1' : '0';

            for (int i = 1; i < n; i++)
            {
                if (num == s[i])
                {
                    count++;
                    total++;
                }
                else
                {
                    m.push_back(count);
                    count = 0;
                }
            }

            m.push_back(count);

            for (auto x : m)
            {
                // cout<<x<<' ';
                sum = x ? (sum + x * a + b) : sum;
            }
            sum = sum + (n - total) * a + b;

            cout << sum << endl;
        }
    }
}