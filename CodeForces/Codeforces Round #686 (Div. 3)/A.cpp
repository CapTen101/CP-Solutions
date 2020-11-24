#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int it;

        if (n % 2 != 0)
        {
            it = n / 2;
            it++;

            for (int i = n; i > 0; i--)
            {
                if (i == it)
                {
                    cout << 1 << " ";
                    continue;
                }
                if (i == 1)
                {
                    cout << it << " ";
                    continue;
                }
                cout << i << " ";
            }

            continue;
        }

        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}