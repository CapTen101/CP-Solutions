#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<unsigned ll> w;

        loop(int, i, 1, n + 1)
        {
            w.push_back(pow(2, i));
        }

        int s = 0, e = n - 1;
        ll one = 0, two = 0;

        while (s < e)
        {
            if ((n / 2) % 2 != 0)
            {
                if (s == (n / 2) - 1)
                {
                    one += w[s];
                    two += w[s + 1];
                    break;
                }
            }
            one += w[s];
            one += w[e];
            s++;
            e--;
            two += w[s];
            two += w[e];
            s++;
            e--;
        }
        cout << abs(one - two) << "\n";
    }
}