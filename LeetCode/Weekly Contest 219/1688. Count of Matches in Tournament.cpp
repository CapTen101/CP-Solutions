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

class Solution
{
public:
    int numberOfMatches(int n)
    {
        if (n <= 1)
            return 0;

        if (n % 2 == 0)
            return (n / 2 + numberOfMatches(n / 2));

        else
        {
            return ((n - 1) / 2 + numberOfMatches((n - 1) / 2 + 1));
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}