#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    int n = j - i + 1;
    for (int k = i; k <= n / 2; k++)
        if (s[k] != s[n - k - 1])
            return false;

    return true;
}

int solve(string s, int i, int j)
{
    // if length is 0 or 1, then 0 partition can be done, hence return 0
    if (i >= j)
        return 0;

    // also check if string is a palindorm or not.
    // if yes, then no need to partition this palindrome
    if (isPalindrome(s, i, j))
        return 0;

    // k goes from i ->j-1.
    // why (j-1)? => because  i->k and k+1->j requires k till j-1 only
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // the 1 means no. of partitions from i->k + k+1->j and then one for between those two temp answers
        int temp_ans = solve(s, i, k) + solve(s, k + 1, j) + 1;
        ans = min(ans, temp_ans);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string test = "ababbbabbababa";
    cout << solve(test, 0, test.size() - 1);
}