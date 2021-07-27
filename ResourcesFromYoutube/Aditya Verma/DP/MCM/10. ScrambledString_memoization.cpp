#include <bits/stdc++.h>
using namespace std;

bool isScramble(string a, string b, unordered_map<string, bool> &dp)
{
    // invalid case
    if (a.size() != b.size())
        return false;

    // if both are null
    if (a.empty() and b.empty())
        return true;

    // if strings are equal
    if (a.compare(b) == 0)
        return true;

    // length sould be greater than or equal to 1
    if (a.size() <= 1)
        return false;

    // BASE CONDITION OVER...

    string key = "";
    key = a + " " + b;
    if (dp.find(key) != dp.end())
        return dp[key];

    // checking for same characters in both strings
    int count[26] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return false;

    int n = a.size();
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (isScramble(a.substr(0, i), b.substr(n - i), dp) && isScramble(a.substr(i), b.substr(0, n - i), dp))
            return true;

        if (isScramble(a.substr(0, i), b.substr(0, i), dp) && isScramble(a.substr(i), b.substr(i), dp))
            return true;
    }

    return dp[key] = flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // key: str -> a + " " + b

    unordered_map<string, bool> dp;
    cout << isScramble("great", "eatgr", dp);
}