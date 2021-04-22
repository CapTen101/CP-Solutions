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

int maxMeetings(int s[], int end[], int n)
{

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
        v.push_back(make_pair(end[i], s[i]));

    sort(v.begin(), v.end());

    int res = 1;
    int fin = v[0].first;

    for (int i = 1; i < n; i++)
    {
        if (fin < v[i].second)
        {
            res++;
            fin = v[i].first;
        }
    }

    v.clear();

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}