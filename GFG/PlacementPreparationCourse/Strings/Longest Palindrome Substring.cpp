#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}

string longestPalindrome(string s)
{
    int l, r, start = 0;
    int maxlength = 1;

    int n = s.length();

    for (int i = 1; i < n; i++)
    {
        // for odd length palindrome string
        l = i - 1;
        r = i + 1;
        while (s[l] == s[r] && l >= 0 && r < n)
        {
            if (r - l + 1 > maxlength)
            {
                start = l;
                maxlength = r - l + 1;
            }
            l--;
            r++;
        }

        //for even length palindrome string
        l = i - 1;
        r = i;

        while (s[l] == s[r] && l >= 0 && r < n)
        {
            if (r - l + 1 > maxlength)
            {
                maxlength = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    string res;

    for (int i = start; i < start + maxlength; i++)
    {
        res.push_back(s[i]);
    }

    return res;
}