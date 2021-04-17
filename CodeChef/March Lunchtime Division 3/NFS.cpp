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
        ll u, v, a, s;
        cin >> u >> v >> a >> s;

        ll vel_turn = sqrt(pow(u, 2) - 2 * a * s);

        if (vel_turn <= v)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}