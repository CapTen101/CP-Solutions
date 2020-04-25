#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007
int sumarray(int a[], int sizeofa, int b[], int sizeofb)
{
    int sizeofc = sizeofa > sizeofb ? (sizeofa + 1) : (sizeofb + 1);
    int c[sizeofc];
    int frontpart = 0;
    for (int i = sizeofa - 1; i >= 0; i--)
    {
        c[i] = (frontpart + a[i] + b[i]) % 10;
        frontpart = ((a[i] + b[i]) - ((a[i] + b[i]) % 10)) % 10;

        if (i == 0 && sizeofb > sizeofa)
        {
            
        }
    }
}
int main()
{
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int m;
//     cin >> m;
//     int b[m];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }
//     sumarray(a, n, b, m);
vector<int> a;
a.pb(4);
a.pb(28);
cout<<a.size();
}