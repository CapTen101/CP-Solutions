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

    start
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[0])
            {
                cout << -1 << endl;
                possible = false;
                break;
            }
        }
        if (!possible)
            continue;

        int pos = 0, count = 0, ptr = 0;
        // while (ptr < n)
        // {
        //     if (arr[pos] < arr[ptr])
        //     {
        //         pos = ptr - 1;
        //         count++;
        //     }
        //     ptr++;
        // }

        stack<int> s;
        s.push(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= s.top())
                s.push(arr[i]);
            if (arr[i] > s.top())
            {
                s.pop();
                s.push(arr[i]);
                count++;
            }
        }

        count++;

        cout << count << "\n";
    }
}