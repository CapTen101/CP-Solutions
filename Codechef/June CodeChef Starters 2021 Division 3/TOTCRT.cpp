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

        vector<string> s3(n);
        vector<int> c3(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s3[i] >> c3[i];
        }

        vector<string> s2(n);
        vector<int> c2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s2[i] >> c2[i];
        }

        vector<string> s1(n);
        vector<int> c1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s1[i] >> c1[i];
        }

        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s1[i]] += c1[i];
            m[s2[i]] += c2[i];
            m[s3[i]] += c3[i];
        }

        vector<int> ans;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            ans.push_back(i->second);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        cout << "\n";
    }
}