#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
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
        ll n, k;
        cin >> n >> k;

        ll cost;

        vector<int> a;

        FOR(i, 0, n)
        cin >> a[i];

        vector<int> one;

        FOR(i, 0, n)
        {
            if (a[i] == 1)
                one.push_back(i);
        }

        FOR(i, 0, one.size())
        {
            int l, r;

            if (one[i] < k)
            {
                l = 0;
                (a.size() > k) ? (r = k) : (r = a.size() - 1);
            }
            else
            {
                l = one[i] - k / 2;
                r = one[i] + k / 2;
            }

            FOR(j, l, r)
            {
                cost += a[j];
            }

            a[one[i]] = 0;
        }

        cout << cost << endl;
    }
}