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

bool canPlaceFlowers(vector<int> flowerbed, int n)
{
    // Leetcode's approach.
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            int prev_index = (i >= 1) ? i - 1 : 0;
            int next_index = (i + 1 < flowerbed.size()) ? i + 1 : flowerbed.size() - 1;

            if (flowerbed[prev_index] == 0 && flowerbed[next_index] == 0)
            {
                n--;
                flowerbed[i] = 1;
            }

            if (n == 0)
                return true;
        }
    }

    return n <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> v = {1, 0, 0, 0, 1};
    cout << canPlaceFlowers(v, 2) << endl;
}