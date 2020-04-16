#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back

ll fun(ll N, ll P, ll Q, ll M)
{
    if (N == 0)
    {
        return P % M;
        // return P;
    }
    if (N == 1)
    {
        return Q % M;
        // return Q;
    }

    return (fun(N - 1, P, Q, M) + fun(N - 2, P, Q, M) + fun(N - 1, P, Q, M) * fun(N - 2, P, Q, M)) % M;
}

int main()
{
    long t;
    cin >> t;
    long long M = 1000000007;

    // loop(l, i, 0, t)                 using the above function...recursive call
    // {
    //     ll p, q, n;
    //     cin >> p >> q >> n;
    //     cout << fun(n, p, q, M) << endl;
    // }

    loop(long, j, 0, t){
        long long p, q, n;
        cin >> p >> q >> n;
        long long loss[n+1];
        loss[0] = p;
        loss[1] = q;

        loop(long long, i, 2, n+1){
            loss[i] = (loss[i-1] + loss[i-2] + loss[i-1]*loss[i-2])%M; 
        }

        cout<<loss[n]<<endl;
    }
}