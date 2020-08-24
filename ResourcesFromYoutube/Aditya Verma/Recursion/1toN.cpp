#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

void print(int n)
{
    //base condition
    if (n == 1)
    {
        cout << 1;
        return;
    }
    // hypothesis
    print(n - 1);

    // induction - to continue our work and do something
    cout << n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    print(5);
}