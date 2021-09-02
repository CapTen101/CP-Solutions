#include <bits/stdc++.h>
using namespace std;

bool helper(string str, unordered_set<string> &s, int i, unordered_map<string, unordered_map<int, bool>> &dp)
{

    if (str.size() == 0)
        return true;
    if (str.size() and i == str.size())
        return false;

    if (dp.find(str) != dp.end())
        return dp[str][i];

    string temp = str.substr(0, i + 1);
    if (s.find(temp) != s.end()) // word found
    {
        bool temp = helper(str, s, i + 1, dp) || helper(str.substr(i + 1), s, 0, dp);
        return dp[str][i] = temp;
    }
    else // not found
    {
        bool temp = helper(str, s, i + 1, dp);
        return dp[str][i] = temp;
    }
}
bool wordBreak(string str, vector<string> &dict)
{
    unordered_set<string> s;
    for (string st : dict)
        s.insert(st);
    unordered_map<string, unordered_map<int, bool>> dp;
    return helper(str, s, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> dict = {"ab", "bcd", "b", "a"};
    string s = "abcd";
    cout << (wordBreak(s, dict) ? "present" : "not present") << endl;
}