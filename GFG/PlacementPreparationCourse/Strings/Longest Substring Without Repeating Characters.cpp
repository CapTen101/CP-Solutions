// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string str)
{
    int n = str.length();
    // int n = strlen(str);

    int l = 0;
    int r = 0;
    int count = 0;
    int maxcount = 0;

    map<char, int> m;

    while (l <= r && r < n)
    {
        if (m.find(str[r]) == m.end()) // if not found in the map
        {
            m.insert({str[r], r});
            count++;
            r++;
            maxcount = max(count, maxcount);
        }
        else // if found
        {
            auto samechar = m.find(str[r]);
            count = samechar->second - l;
            maxcount = max(count, maxcount);

            m.clear();

            l = samechar->second;
            r = l;
            count = 1;

            m.insert({str[r], r});

            r++;
        }
    }

    return maxcount;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin >> ws;
    while (t--)
    {
        string str;
        getline(cin, str);
        cout << str;
        cout << SubsequenceLength(str) << "\n";
    }
}
// } Driver Code Ends