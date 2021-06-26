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

        string s;
        cin >> s;

        ll res = 0;
        int first = -1, last;

        vector<int> star;

        // first
        FOR(i, 0, s.length())
        {
            if (s[i] == '*' && first == -1)
            {
                s[i] = 'x';
                first = i;
                res++;
            }

            star.push_back(i);
        }

        // last
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                s[i] = 'x';
                last = i;
                res++;
                break;
            }
        }

        if (star.size() == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (star.size() == 2)
        {
            cout << 2 << endl;
            continue;
        }

        
        // 'x' encountered
        int enc = -1;

        FOR(i, 0, s.length())
        {
            if (s[i] == '*' && enc != -1)
            {
                if (i - enc <= k && res < 3)
                {
                    res++;
                    s[i] == 'x';
                    enc = i;
                }
            }
            else if (s[i] == 'x')
                enc = i;
        }

        cout << res << endl;
    }
}