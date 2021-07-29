#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &a, int position, vector<bool> &checked, vector<int> &dp)
{
    if (dp[position] != -1)
        return dp[position];

    if (position < 0 || position >= a.size())
        return false;

    if (a[position] == 0)
        return true;

    checked[position] = true;
    int left = (position - a[position]);
    int right = (position + a[position]);
    bool check_left = false, check_right = false;

    if (left >= 0 and left < a.size() and checked[left] == false)
        check_left = helper(a, left, checked, dp);
    if (right >= 0 and right < a.size() and checked[right] == false)
        check_right = helper(a, right, checked, dp);

    return dp[position] = (check_left || check_right);
}

bool canReach(vector<int> &a, int start)
{
    if (a[start] == 0)
        return true;

    vector<bool> checked(a.size(), false);
    vector<int> dp(a.size(), -1);

    return helper(a, start, checked, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}