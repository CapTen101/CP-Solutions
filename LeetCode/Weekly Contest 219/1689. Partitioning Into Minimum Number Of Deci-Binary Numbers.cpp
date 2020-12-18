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
    int minPartitions(string n)
    {
        char *ch;
        ch = &n[0];

        int character_max = '0';

        for (int i = 0; i < strlen(ch); i++)
        {
            // character_max = max(character_max, ch[i]);
            if (ch[i] >= character_max)
                character_max = ch[i];
        }

        return character_max - '0';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}