#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)

int main()
{
    int n;

    while (n != 42)
    {
        cin >> n;
        if (n == 42)
            break;
        cout << n << endl;
    }

    return 0;
}