// infinite transactions:

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

// infinite transactions
int maxProfit(vector<int> &p)
{
    int profit = 0;
    int bd = p[0];
    int sd = p[0];
    int n = p.size();

    for (int i = 1; i < n; i++)
    {
        if (p[i] >= sd)
            sd = p[i];
        else
        {
            profit += (sd - bd);
            bd = p[i];
            sd = p[i];
        }
    }

    // to settle the last vala sale, 'cause that gets ignored because of absence of next value which will eventually compare it
    profit += (sd - bd);

    return profit;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}