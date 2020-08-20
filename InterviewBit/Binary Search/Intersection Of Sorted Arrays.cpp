#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

vector<int> intersect(vector<int> a, vector<int> b)
{
    int an = a.size();
    int bn = b.size();
    int n = min(an, bn);
    vector<int> v;

    int aptr = 0;
    int bptr = 0;

    while (aptr < an && bptr < bn)
    {
        if (a[aptr] == b[bptr])
        {
            v.push_back(a[aptr]);
            aptr++;
            bptr++;
        }
        else if (a[aptr] > b[bptr])
            bptr++;
        else if (a[aptr] < b[bptr])
            aptr++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    intersect({2, 3, 3, 4, 4, 6, 8, 8, 9, 9, 10, 10, 11, 14, 14, 15, 16, 18, 20, 21, 23, 23, 24, 25, 28, 29, 33, 33, 35, 35, 37, 38, 38, 40, 41, 42, 42, 44, 44, 47, 47, 49, 49, 52, 53, 56, 58, 61, 62, 62, 63, 64, 65, 65, 66, 67, 67, 67, 68, 69, 72, 74, 76, 76, 79, 80, 82, 82, 83, 83, 83, 84, 85, 85, 85, 85, 87, 91, 93, 94, 94, 94, 95, 96, 101, 101}, {12, 12, 20, 39, 42, 44, 47, 73, 77});
}