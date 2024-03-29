#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define prime 3
#define start \
    int t;    \
    cin >> t; \
    while (t--)

ll createHashValue(string str, int n)
{
    ll result = 0;

    for (int i = 0; i < n; i++)
    {
        result += (ll)(str[i] * (ll)pow(prime, i));
    }
    return result;
}

ll reCalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patlength)
{
    ll newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (ll)(str[newIndex] * (ll)pow(prime, patlength - 1));
    return newHash;
}

bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2)
{
    if (end1 - start1 != end2 - start2)
        return false;

    while (start1 <= end1 && start2 <= end2)
    {
        if (str1[start1] != str2[start2])
            return false;

        start1++;
        start2++;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string str = "asfuabfjafwiafwibajbdaosfafbafbaunsoaaffa";
    string pat = "af";

    ll strHash = createHashValue(str, pat.length());
    ll patHash = createHashValue(pat, pat.length());

    for (int i = 0; i <= str.length() - pat.length(); i++)
    {
        if (patHash == strHash && checkEqual(str, pat, i, i + pat.length() - 1, 0, pat.length() - 1))
        {
            cout << i << endl;
            return 0;
        }

        if (i < str.length() - pat.length())
            strHash = reCalculateHash(str, i, i + pat.length(), strHash, pat.length());
    }
}