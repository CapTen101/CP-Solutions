#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)

long gcd(long a, long b)
{
    return b ? gcd(b, a % b) : a;
}

long lcm(long a, long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int t;
    cin >> t;

    loop(int, i, 0, t)
    {
        long a, b;
        cin >> a >> b;

        long gcD = gcd(a, b);
        long lcM = lcm(a, b);

        cout << gcD << " " << lcM << endl;
    }
}