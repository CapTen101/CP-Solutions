#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int u = 1; u <= t; u++)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if (n == 0)
        {
            if (k == 1)
            {
                cout << "0" << endl;
                goto hello;
            }
            int ans = 0;
            int p = 1;
            for (int i = 1; i >= 1; i++)
            {
                ans = ans + (2 * i);
                p++;
                if (p == k)
                {
                    cout << ans << endl;
                    goto hello;
                }
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                ans = ans + (2 * i);
            }
            int p = 0;
            int i;
            for (i = n; i >= n; i++)
            {
                if (i == n)
                {
                    p = p + 1;
                }
                else
                {
                    p = p + 2;
                }
                ans += (2 * i);

                if (p >= k)
                {
                    goto hi;
                }
            }
        hi:
            cout << "";
            if (p == k)
            {

                cout << ans - n << endl;
            }
            else
            {
                ans = ans - (2 * i) + n;
                cout << ans << endl;
            }
        }
    hello:
        cout << "";
    }
}