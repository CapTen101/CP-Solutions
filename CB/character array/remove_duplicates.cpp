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

void removeDuplicate(char str[])
{

    int p = 0;
    int len = strlen(str);

    FOR(c, 0, len)
    {
        if (str[c] != str[p])
        {
            p++;
            str[p] = str[c];
        }
    }

    // to terminate the string
    str[p + 1] = '\0';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    char str[] = "ccooooddinnggg";
    removeDuplicate(str);
    cout << str;
}