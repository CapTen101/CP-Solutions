#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)

long long binaryexpo(unsigned long long a, long b, int n)
{
    a = a % n;
    if (b == 0)
        return 1;
    unsigned long long res = binaryexpo(a%n, b / 2, n);
    if (b % 2)
        return res * res * a%n;
    else
        return res * res;
}

int main()
{
    int c;
    cin >> c;

    unsigned long long int *x = new unsigned long long int();
    long int *y = new long int();
    int *n = new int();

    loop(int, i, 0, c)
    {
        cin >> x[i] >> y[i] >> n[i];
    }

    int zero;
    cin >> zero;

    loop(int, i, 0, c)
    {
        unsigned long long res = binaryexpo(x[i], y[i], n[i]);
        cout << res << endl;
    };
}