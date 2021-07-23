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
        string s;
        cin >> s;
        int n = s.size();

        unordered_map<char, int> ch;
        for (int i = 0; i < n; i++)
            ch[s[i]]++;

        int red = 0, green = 0; // unique chars

        for (auto i = ch.begin(); i != ch.end(); i++)
        {
            i->second--;
            red++;
        }

        for (auto i = ch.begin(); i != ch.end(); i++)
        {
            if (i->second > 0)
            {
                i->second--;
                green++;
            }
        }

        if (green == 0)
        {
            if (red % 2 == 0)
            {
                cout << red / 2 << endl;
                continue;
            }
            else
            {
                red--;
                cout << red / 2 << endl;
                continue;
            }
        }

        if (red == green)
            cout << red << endl;
        else
        {
            int rem = 0;
            for (auto i = ch.begin(); i != ch.end(); i++)
                if (i->second > 0)
                    rem += i->second;

            if ((red - green) % 2 == 0)
                cout << red - (red - green) / 2 << endl;
            else
            {
                red--;
                cout << red - (red - green) / 2 << endl;
            }
        }
    }
}