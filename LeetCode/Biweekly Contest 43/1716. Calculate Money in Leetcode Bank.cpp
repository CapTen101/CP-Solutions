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
    int totalMoney(int n)
    {
        int k = n / 7;   // total number of complete set of weeks
        int rem = n % 7; // extra days

        // Below sum can be easily derived from Arithmetic Progression of the sequence
        long long sum = 28 * k + (7 * (k - 1) * (k)) / 2;

        // If n is s multiple of 7 without any extra days, then return the above sum.
        if (rem == 0)
            return sum;

        // otherwise, k++ and calculate the remainder days sum
        k++;

        // below sum strategy can be easily observed from the example testcases
        for (int i = 1; i <= rem; i++)
        {
            sum += k;
            k++;
        }

        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}