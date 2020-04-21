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

    vector<ll> fib;
    fib.pb(1);
    fib.pb(2);
    ll sum = 2;

    for (int i = 2;i<100; i++)
    {
        fib.pb(fib[i - 1] + fib[i - 2]);
        
        if (fib[i] % 2 == 0)
        {
            sum += fib[i];
        }

        if (fib[i] > 4000000)
        {
            break;
        }
    }
    cout<<sum;
}