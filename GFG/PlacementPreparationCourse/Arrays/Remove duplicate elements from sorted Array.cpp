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

int remove_duplicate(int A[], int N)
{
    int num = 0;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        v.push_back(A[i]);
    }

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            v.erase(v.begin() + i);
        }
    }

    return v.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
}