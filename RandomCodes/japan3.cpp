#include <bits/stdc++.h>
#include <map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
typedef long long int ll;
using namespace std;
ll mod1 = 1000000007;
ll mod2 = 67280421310721;
ll mod3 = 998244353;
ll INF = 1e18;

ll binpow1(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpow2(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

map<ll, ll> fact(ll n)
{
    map<ll, ll> factorization;
    ll c = 0;
    while (n % 2 == 0)
    {
        c++;
        n /= 2;
    }
    if (c > 0)
    {
        factorization.insert({2, c});
    }
    c = 0;
    for (ll d = 3; d * d <= n; d += 2)
    {
        while (n % d == 0)
        {
            c++;
            n /= d;
        }
        if (c > 0)
        {
            factorization.insert({d, c});
        }
        c = 0;
    }
    if (n > 1)
    {
        factorization.insert({n, 1});
    }
    return factorization;
}

ll a[] = {0, 0, 1, -1};
ll b[] = {1, -1, 0, 0};
map<pair<ll, ll>, ll> D, w;
ll m, n;
char arr[31][31];

bool ispos(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

void dijkstraalgopathfinder(ll srci, ll srcj)
{

    D[{srci, srcj}] = 0;
    set<pair<ll, pair<ll, ll>>> Q;
    Q.insert({0LL, {srci, srcj}});

    while (!Q.empty())
    {

        auto top = Q.begin();
        int u = (top->second).first;
        int v = (top->second).second;
        Q.erase(top);

        for (int i = 0; i < 4; i++)
        {
            int x = u + a[i];
            int y = v + b[i];
            if (ispos(x, y))
            {
                if (arr[x][y] == '#')
                {
                    if (D[{x, y}] > (D[{u, v}] + w[{u, v}] + 1LL))
                    {
                        if (Q.find({D[{x, y}], {x, y}}) != Q.end())
                        {
                            Q.erase({D[{x, y}], {x, y}});
                        }

                        D[{x, y}] = D[{u, v}] + 1 + w[{u, v}];
                        Q.insert({D[{x, y}], {x, y}});
                        w[{x, y}] = 1 + w[{u, v}];
                    }
                }
                else
                {
                    if (D[{x, y}] > (D[{u, v}] + 1))
                    {
                        if (Q.find({D[{x, y}], {x, y}}) != Q.end())
                        {
                            Q.erase({D[{x, y}], {x, y}});
                        }

                        D[{x, y}] = D[{u, v}] + 1;
                        Q.insert({D[{x, y}], {x, y}});
                        w[{x, y}] = w[{u, v}];
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll si, sj, ei, ej;
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (arr[i][j] == 'G')
            {
                ei = i;
                ej = j;
            }
            D[{i, j}] = INF;
            w[{i, j}] = 0;
        }
    }
    dijkstraalgopathfinder(si, sj);
    cout << D[{ei, ej}];

    return 0;
}