#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long int a, b;
        cin >> a >> b;

        while (b % 2 == 0)
        {
            b = b / 2;
        }

        if (b == 1)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}