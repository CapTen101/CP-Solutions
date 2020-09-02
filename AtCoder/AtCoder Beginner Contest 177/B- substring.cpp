#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);

    int d, t, s;
    cin >> d >> t >> s;

    if (d == 0)
    {
        cout << "Yes";
        return 0;
    }
    if (s <= 0)
    {
        cout << "No";
        return 0;
    }

    int time = d / s;
    if (time <= t)
        cout << "Yes";
    else
        cout << "No";
}