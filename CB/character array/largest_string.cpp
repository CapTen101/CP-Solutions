#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;

    // THIS INPUT INSERTS A '\N' AFTER PRESSING ENTER WHICH NEEDS TO BE AVOIDED.
    cin >> n;

    char a[1000];

    // THIS CIN.GET() IS DONE IS ORDER TO READ AND VOID THE PROGRAM TO READ NULL CHARACTER AS A NULL STRING INPUT!
    cin.get();

    for (int i = 0; i < n; i++)
    {
        cin.getline(a, 1000);
        cout << a << endl;
    }
}