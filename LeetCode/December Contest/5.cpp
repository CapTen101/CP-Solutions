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
    // if (n == 0)
    //     return true;

    // vector<int> planted;
    // int total_plants_possible = 0;

    // for (int i = 0; i < flowerbed.size(); i++)
    // {
    //     if (flowerbed[i] == 1)
    //         planted.push_back(i);
    // }

    // if (planted.empty())
    // {
    //     int n = flowerbed.size();

    //     if (n % 2 != 0)
    //         return n / 2 + 1;

    //     else
    //         return n / 2;
    // }

    // if (planted.size() == 1)
    // {
    //     int index = planted[0];
    //     int before_zeroes = index;
    //     int after_zeroes = flowerbed.size() - index - 1;

    //     total_plants_possible += (before_zeroes / 2);
    //     total_plants_possible += (after_zeroes / 2);

    //     return total_plants_possible >= n ? true : false;
    // }

    // for (int i = 0; i < planted.size(); i++)
    // {
    //     int first = planted[i] + 1;
    //     int second = planted[i + 1] + 1;
    //     int num_of_zeroes = second - first - 1;

    //     if (num_of_zeroes % 2 != 0)
    //         total_plants_possible += (num_of_zeroes / 2);
    //     else
    //         total_plants_possible += (num_of_zeroes / 2 - 1);

    //     if (total_plants_possible >= n)
    //         return true;
    // }

    // int first_one = planted[0];
    // int last_one = planted[planted.size() - 1];

    // if (flowerbed[0] == 0)
    // {
    //     int zeroes = first_one;
    //     total_plants_possible += (zeroes / 2);
    // }

    // if (flowerbed[flowerbed.size() - 1] == 0)
    // {
    //     int zeroes = flowerbed.size() - last_one - 1;
    //     total_plants_possible += (zeroes / 2);
    // }

    // return total_plants_possible >= n ? true : false;

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