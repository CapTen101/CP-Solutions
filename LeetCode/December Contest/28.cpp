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
    int reachNumber(int target)
    {
        target = abs(target);
        int i = 1;

        long long sum = 0;

        while (sum < target)
        {
            sum += i * (i + 1) / 2;
            i++;
        }

        int res = sum - target;

        if (sum == target)
            return i;
        else if (res % 2 == 0)
            return i;
        else
        {
            return i + ((i & 1) ? 1 : 2);
        }
    }
};

// O(1) Solution

// class Solution {
// public:
//     int reachNumber(int target) {
//         target = abs(target);
//         long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
//         long long sum = n * (n+1) / 2;
//         if (sum == target) return n;
//         long long res = sum - target;
//         if ((res&1) == 0)
//             return n;
//         else
//             return n+((n&1) ? 2 : 1);

//     }
// };

int main()
{
    ios_base::sync_with_stdio(false);
}