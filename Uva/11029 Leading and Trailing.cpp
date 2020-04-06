#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)

long long binaryexpotrail(unsigned long long a, long b)
{

    if (b == 0)
        return 1;
    unsigned long long res = binaryexpotrail(a, b / 2);
    if (b % 2)
        return ((res * res * a) % 1000);
    else
        return ((res * res) % 1000);
}

long long binaryexpolead(unsigned long long a, long b)
{
    static int x = 1000;

    if (b == 0)
        return 1;
    unsigned long long res = binaryexpolead(a, b / 2);
    if (b % 2)
    {
    check1:
        if (((res * res * a) % x) < x)
            return ((res * res * a));
        else
        {
            x = x * 10;
            goto check1;
        }
    }

    else
    {
    check:
        if (((res * res) % x) < x)
            return ((res * res));
        else
        {
            x = x * 10;
            goto check;
        }

        return ((res * res) % 1000);
    }
}

int main()
{

    int c;
    cin >> c;

    unsigned long long int *n = new unsigned long long int();
    long int *k = new long int();

    loop(int, i, 0, c)
    {
        cin >> n[i] >> k[i];
    }

    loop(int, i, 0, c)
    {
        long long trail = binaryexpotrail(n[i], k[i]);
        long long lead = binaryexpotrail(n[i], k[i]);

        cout << lead << "..." << trail << endl;
    };
}