#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s, n;
        bool possible = false;
        cin >> n >> s;
        int p[n] = {0};
        int type[n];
        vector<int> defender, forward;
        int moneyleft = 100 - s;

        loop(int, i, 0, n)
        {
            cin >> p[i];
        }
        loop(int, i, 0, n)
        {
            cin >> type[i];
        }

        loop(int, i, 0, n)
        {
            if (type[i] == 0)
                defender.pb(p[i]);
            else if (type[i] == 1)
                forward.pb(p[i]);
        }

        sort(defender.begin(), defender.end());
        sort(forward.begin(), forward.end());

        loop(int, i, 0, defender.size())
        {
            loop(int, j, 0, forward.size())
            {
                if (defender[i] + forward[j] <= moneyleft)
                {
                    cout << "yes" << endl;
                    possible = true;
                    break;
                }

                else
                    possible = false;
            }
            if (possible == true)
                break;
        }
        if (possible == false)
            cout << "no" << endl;
    }
}