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
    bool arrayStringsAreEqual(vector<string> &w1, vector<string> &w2)
    {
        // O(n) time and space approach:
        // string s1, s2;

        // for (int i = 0; i < w1.size(); i++)
        //     s1.append(w1[i]);

        // for (int i = 0; i < w2.size(); i++)
        //     s2.append(w2[i]);

        // return s1 == s2 ? true : false;


        // O(1) space approach below:

        int o1, i1;
        int o2, i2;

        o1 = 0;
        o2 = 0;
        i1 = 0;
        i2 = 0;

        while (o1 < w1.size() && o2 < w2.size())
        {
            if (w1[o1][i1] != w2[o2][i2])
                return false;

            if (i1 == w1[o1].size() - 1)
            {
                o1++;
                i1 = 0;
            }
            else
                i1++;

            if (i2 == w2[o2].size() - 1)
            {
                o2++;
                i2 = 0;
            }
            else
                i2++;
        }

        return o1 == w1.size() && o2 == w2.size() ? true : false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}