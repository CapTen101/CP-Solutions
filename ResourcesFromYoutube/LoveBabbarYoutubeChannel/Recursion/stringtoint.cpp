#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int stringtoint(string s)
{
    if (s.length() == 1)
        return s[0] - '0';

    double y = stringtoint(s.substr(1));

    double x = s[0] - '0';

    x = x * pow(10, s.length() - 1) + y;

    return int(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    string s = "8743715";
    cout << stringtoint(s) << "\n";
}