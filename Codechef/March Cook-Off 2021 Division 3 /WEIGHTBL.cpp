#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
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
        ll w1, w2, x1, x2, m;
        cin >> w1 >> w2 >> x1 >> x2 >> m;

        if (m * x1 <= (w2 - w1) && m * x2 >= (w2 - w1))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}