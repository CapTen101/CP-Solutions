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

class Solution
{
public:
    bool validMountainArray(vector<int> &v)
    {
        // index of the max element of the array
        int index = -1;

        // size less then 3 is invalid for mountain array
        if (v.size() < 3)
            return false;

        // checking for increasing monotocity
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > v[i - 1])
                continue;
            else
            {
                index = i - 1; // max element index
                break;
            }
        }

        // checking if the max element is the  first or last index or not.
        // If YES, then that's invalid.
        // If NO, then proceed.
        if (index == -1 || index == 0)
            return false;

        // checking for decreasing monotocity
        for (int i = index + 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1])
                continue;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}