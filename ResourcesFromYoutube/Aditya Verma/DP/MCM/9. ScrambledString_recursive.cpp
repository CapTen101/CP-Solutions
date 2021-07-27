#include <bits/stdc++.h>
using namespace std;

bool isScramble(string a, string b)
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

    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        // substr(starting_index, length) OR substr(starting_index)
        // if yes, the substrings are swapped
        if (isScramble(a.substr(0, i), b.substr(n - i)) && isScramble(a.substr(i), b.substr(0, n - i)))
            return true;
        // if no, the substrings are not swapped
        if (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i), b.substr(i)))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}