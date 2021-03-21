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

bool check(long double x)
{
    if (x >= 0)
    {

        ll sr = sqrt(x);

        return (sr * sr == x);
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    start
    {
        int verdict = 0;
        // printf("%d\n", 1);
        // fflush(stdout);
        // scanf("%d\n", &verdict);
        cout << 1 << endl;
        cin >> verdict;

        ll i = 4;

        while (verdict != 1 && verdict == 0 && i <= 1000000)
        {
            bool chk = check(i);
            if (chk)
            {
                // printf("%lld\n", i);
                // fflush(stdout);
                // scanf("%d\n", &verdict);

                cout << i << endl;
                cin >> verdict;

                i++;
            }
            else
            {
                i++;
                continue;
            }
        }

        if (verdict == -1)
            exit(0);
    }
}