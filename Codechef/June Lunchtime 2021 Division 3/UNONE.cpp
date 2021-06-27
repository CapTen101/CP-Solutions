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

string db(ll n)
{
    vector<int> bn;

    int i = 0;
    while (n > 0)
    {
        bn.push_back(n % 2);
        n = n / 2;
        i++;
    }

    string num = "";
    for (int i = 0; i < bn.size(); i++)
    {
        num += to_string(bn[i]);
    }

    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                swap(a[i], a[n - 1]);
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;

        // // to binary
        // for (int i = 0; i < n; i++)
        // {
        //     a[i] = stoi(db(a[i]));
        // }

        // string full = "";

        // for (int i = 0; i < n; i++)
        // {
        //     full += to_string(a[i]);
        // }
    }
}