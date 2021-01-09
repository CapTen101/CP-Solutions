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
    int maximumGain(string s, int x, int y)
    {

        //         int b=0;
        //         int f=0;

        int tscore = 0;

        int pts = x > y ? x : y;

        // while(b<f)
        // {
        //     if(s[b] == 'a')
        //     {
        //         if(s[])
        //     }
        // }

        int i = 0;
        while (s.size() > 0 && i < s.size())
        {
            if (pts == x) // remove "ab"
            {
                if (s[i] == 'a')
                {
                    if (s[i + 1] == 'b')
                        s.erase(i, 2);
                }
                else
                    i++;
            }
            else if (pts == y) // remove "ba"
            {
            }
        }

        return tscore;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}