#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        if (s.length() < 11)
            cout << s << "\n";
        else
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
    }
}