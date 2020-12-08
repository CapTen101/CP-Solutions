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

vector<vector<int>> spiral_traverse(int n)
{
    vector<vector<int>> v;
    v.resize(n);

    // resizing the entire matrix
    for (int i = 0; i < n; i++)
        v[i].resize(n);

    int num = 1;

    int sr = 0;
    int er = n - 1;
    int sc = 0;
    int ec = n - 1;

    while (sr <= er && sc <= ec)
    {
        // top row
        for (int i = sc; i <= ec; i++)
        {
            v[sr][i] = num;
            num++;
        }
        sr++;

        // end column
        for (int i = sr; i <= er; i++)
        {
            v[i][ec] = num;
            num++;
        }
        ec--;

        if (er > sr)
        {
            // end row
            for (int i = ec; i >= sc; i--)
            {
                v[er][i] = num;
                num++;
            }
            er--;
        }

        if (ec > sc)
        {
            // start column
            for (int i = er; i >= sr; i--)
            {
                v[i][sc] = num;
                num++;
            }
            sc++;
        }
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
}