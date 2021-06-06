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

int thirdMax(vector<int> &a);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {-2147483648, 1, 2};
    cout << thirdMax(v) << endl;
}

int thirdMax(vector<int> &a)
{
    if (a.size() <= 2)
    {
        return *(std::max_element(a.begin(), a.end()));
    }

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int n = a.size();
    max1 = a[0];
    if (a[0] == INT_MIN)
        max1 = a[1];
    bool m3_found = false;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
            if (max3 != INT_MIN)
                m3_found = true;
        }
        else if (a[i] > max2 and a[i] < max1)
        {
            max3 = max2;
            max2 = a[i];
            if (max3 != INT_MIN)
                m3_found = true;
        }
        else if ((a[i] > max3) and (a[i] < max2) and (a[i] < max1))
        {
            max3 = a[i];
            m3_found = true;
        }
        else if (a[i] == INT_MIN && max3 == INT_MIN)
        {
            m3_found = true;
        }
    }

    if (m3_found)
        return max3;
    else
        return max1;
}