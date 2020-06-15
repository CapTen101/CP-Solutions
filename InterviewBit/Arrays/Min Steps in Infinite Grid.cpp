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

int coverPoints(vector<int> &A, vector<int> &B)
{
    int steps = 0;

    for (int i = 0; i < A.size() - 1; i++)
    {
        int x1 = A[i];
        int y1 = B[i];
        int x2 = A[i + 1];
        int y2 = B[i + 1];

        int diffx = abs(x1 - x2);
        int diffy = abs(y1 - y2);

        steps = max(diffx, diffy);
    }
    return steps;
}

int main()
{
    ios_base::sync_with_stdio(false);
}