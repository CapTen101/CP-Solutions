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

    start
    {
        string s;
        cin >> s;

        ll l = 0;

        while (l <= s.length() - 5)
        {
            if (s.substr(l, 5) == "party")
            {
                s[l + 2] = 'w';
                s[l + 3] = 'r';
                s[l + 4] = 'i';

                l += 5;
            }
            else
            {
                l++;
            }
        }

        cout << s << endl;
    }
}