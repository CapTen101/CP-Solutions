#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> white, black;

    // 0 - white
    // 1 - black

    int n;
    cin >> n;
    vector<int> arr(n);
    inarr(0, n, arr);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i])
            black.push_back(i);
        else
            white.push_back(i);
    }

    int length = 0;

    for (int i = 0; i < white.size(); i++)
    {
        length += fabs(white[i] - black[i]);
    }

    cout << "length of wire = " << length << endl;
}