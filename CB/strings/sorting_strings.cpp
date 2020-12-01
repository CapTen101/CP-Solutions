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

// writing our own compare funtion for comparing on the basis of length of strings
bool compare(string s0, string s1)
{
    // if length of the strings is same then return the larger string.
    if (s0.length() == s1.length())
        return s0 < s1;

    return s0.length() < s1.length();
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    cin.get();

    string s[100];

    for (int i = 0; i < n; i++)
    {
        // NOTE: in case of strings, cin.getline() doesn't work instead use --> getline(cin, string array[])
        getline(cin, s[i]);
    }

    // sort() is used for lexicographical sorting the strings inside an array!
    // we are also using our own compare function here.
    sort(s, s + n, compare); // n is the number of strings in the array

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
}