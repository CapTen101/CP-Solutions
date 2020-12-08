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

int numPairsDivisibleBy60(vector<int> &time)
{
    int count = 0;
    int r[60] = {0};

    for (int i = 0; i < time.size(); i++)
    {
        time[i] = time[i] % 60;
        r[time[i]]++;
    }

    for (int i = 1; i < 30; i++)
        count += (r[i] * r[60 - i]);

    count += (r[30] * (r[30] - 1) / 2);

    count += (r[0] * (r[0] - 1) / 2);

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
}