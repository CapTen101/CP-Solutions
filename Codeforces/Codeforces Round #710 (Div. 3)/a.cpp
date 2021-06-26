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
        ll n, m, x;
        cin >> n >> m >> x;

        ll row = x % n;
        if (x % n == 0)
            row = n;

        ll col;

        if (x % n == 0)
            col = x / n;
        else
            col = x / n + 1;

        cout << m * (row - 1) + col << endl;
    }
}