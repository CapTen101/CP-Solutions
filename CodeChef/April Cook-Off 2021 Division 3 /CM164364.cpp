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
        long n, x;
        cin >> n >> x;

        vector<ll> a(n);
        set<int> type;
        map<int, int> freq;
        int max_freq = 0;

        FOR(i, 0, n)
        {
            cin >> a[i];
            type.insert(a[i]);
            freq[a[i]]++;
            max_freq = max(freq[a[i]], max_freq);
        }

        int num_types = type.size();

        if (x > max_freq)
        {
            if ((a.size() - num_types) < x)
            {
                        }
        }
        else
        {
            /* code */
        }

        // cout << "num_types " << num_types << endl;

        if (num_types < x)
        {
            cout << 0 << endl;
            continue;
        }

        num_types -= x;

        cout << num_types << endl;
    }
}