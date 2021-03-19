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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;

        if (w <= (k1 + k2) / 2 && b <= (n - k1 + n - k2) / 2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}