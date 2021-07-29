#include <bits/stdc++.h>
using namespace std;

bool helper(string &a, string &b, string &res, int an, int bn, int resn, vector<vector<vector<int>>> &dp)
{

    if (dp[an][bn][resn] != -1)
        return dp[an][bn][resn];

    if (an == 0 and bn == 0)
    {
        return dp[an][bn][resn] = true;
    }

    if (an > 0 and bn > 0)
    {
        if ((a[an - 1] == res[resn - 1]) and (b[bn - 1] == res[resn - 1]))
            return dp[an][bn][resn] = (helper(a, b, res, an - 1, bn, resn - 1, dp) || helper(a, b, res, an, bn - 1, resn - 1, dp));
        else if (a[an - 1] == res[resn - 1])
            return dp[an][bn][resn] = helper(a, b, res, an - 1, bn, resn - 1, dp);
        else if (b[bn - 1] == res[resn - 1])
            return dp[an][bn][resn] = helper(a, b, res, an, bn - 1, resn - 1, dp);
        else
            return false;
    }
    else if (an == 0 and bn > 0)
    {
        if (b[bn - 1] == res[resn - 1])
            return dp[an][bn][resn] = helper(a, b, res, an, bn - 1, resn - 1, dp);
        else
            return false;
    }
    else
    {
        if (a[an - 1] == res[resn - 1])
            return dp[an][bn][resn] = helper(a, b, res, an - 1, bn, resn - 1, dp);
        else
            return dp[an][bn][resn] = false;
    }
}

bool isInterleave(string a, string b, string res)
{
    int an = a.size();
    int bn = b.size();
    int resn = res.size();

    if (resn == 0)
    {
        if (an == 0 and bn == 0)
            return true;
        else
            return false;
    }

    if (an + bn != resn)
        return false;

    vector<vector<vector<int>>> dp(an + 1, vector<vector<int>>(bn + 1, vector<int>(resn + 1, -1)));

    return helper(a, b, res, an, bn, resn, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}