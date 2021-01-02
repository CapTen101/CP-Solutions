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
    int reachNumber(int x)
    {
        x = abs(x);
        int n = ceil(sqrt(2 * x) - 1); // starting point for our pointer;

        while (true)
        {
            int upper = n * (n + 1) / 2;

            if (upper >= x && (upper - x) % 2 == 0)
                break;

            else
                n += 1;
        }

        return n;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}