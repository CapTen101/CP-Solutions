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
        int n;
        cin >> n;

        // cout << n << " ";
        vector<int> v(n);

        for (int i = 1; i <= n; i++)
            v[i - 1] = i;

        if (v.size() % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                swap(v[i], v[i + 1]);
            }
        }
        else
        {
            for (int i = 0; i < n - 1; i += 2)
            {
                swap(v[i], v[i + 1]);
            }

            for (int i = 0; i < n - 2; i++)
                cout << v[i] << " ";

            cout << v[v.size() - 1] << " " << v[v.size() - 2] << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        cout << endl;
    }
}