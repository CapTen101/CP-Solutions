#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(int x, int y, string &s1, string &s2)
    {
        if (x == 0 || y == 0)
            return 0;

        // if last element is common, take it from both strings
        if (s1[x - 1] == s2[y - 1])
            return 1 + lcs(x - 1, y - 1, s1, s2);
        // if not common, then remove one element from either of the two strings
        else
            return max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
    }
};

int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
