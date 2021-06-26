#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back

int main()
{

    int t;
    cin >> t;

    loop(int, i, 0, t)
    {
        int x, n, m;
        cin >> x >> n >> m;

        int absorbby2, strikeminus10, spell;

        do
        {
            absorbby2 = x / 2 + 10;
            strikeminus10 = x - 10;
            if (absorbby2 >= strikeminus10 && n > 0)
            {
                spell = absorbby2;
                n--;
            }
            else if (strikeminus10 >= absorbby2 && m > 0)
            {
                spell = strikeminus10;
                m--;
            }
            else
            {
                break;
            }

        DOspell:

            x -= spell;

        } while ((x > 0) && (n || m));

        if (x <= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}