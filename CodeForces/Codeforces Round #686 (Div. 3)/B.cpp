#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> count(1000000, 0);
        vector<int> index(n, 0);

        int minnum = INT_MAX, minindex = -1;

        vector<int> a(n);
        set<int> s;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            minnum = min(a[i], minnum);
            count[a[i]]++;
        }

        if (n == 2)
        {
            if (a[0] == a[1])
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                if (a[0] < a[1])
                    cout << 1 << endl;
                else
                    cout << 2 << endl;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] < minnum)
            {
                minnum = min(a[i], minnum);
                minindex = i;
            }

            if (s.find(a[i]) == s.end())
                s.insert(a[i]);

            else
            {
            }
        }

        for (int i = 0; i < n; i++)
        {
            count[a[i] - 1]++;   // keeps the count
            index[a[i] - 1] = i; // keeps the index
        }

        // minimum number across the group
        for (int i = 0; i < n; i++)
        {
            if (count[i] == 1)
            {
                minindex = index[i];
            }
        }

        cout << minindex + 1 << endl;
    }
}