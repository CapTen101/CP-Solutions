#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define pb push_back

int main()
{
    long t;
    cin >> t;

    loop(long, i, 0, t)
    {
        ll a, b, c, k;
        cin >> a >> b >> c;
        k = (c-b)/a;
        ll ans;
        ans = k*a+b;
       
        cout<<ans<<endl;
    }
}