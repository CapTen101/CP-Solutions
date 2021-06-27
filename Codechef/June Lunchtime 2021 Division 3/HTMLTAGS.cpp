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
        string tag;
        cin >> tag;
        int n = tag.size();

        if (n <= 3)
        {
            cout << "Error" << endl;
            continue;
        }

        if (!(tag[0] == '<'))
        {
            cout << "Error" << endl;
            continue;
        }
        else if (!(tag[1] == '/'))
        {
            cout << "Error" << endl;
            continue;
        }
        else if (!(tag[n - 1] == '>'))
        {
            cout << "Error" << endl;
            continue;
        }

        bool ans = true;
        for (int i = 2; i < n - 1; i++)
        {
            if (!(isdigit(tag[i]) || (tag[i] >= 97 && tag[i] <= 122)))
            {
                ans = false;
                break;
            }
        }

        cout << (ans ? "Success" : "Error") << endl;
    }
}