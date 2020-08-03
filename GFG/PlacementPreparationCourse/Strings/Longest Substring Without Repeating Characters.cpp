// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string str)
{
    int n = str.length();

    int l = 0;
    int r = 0;
    int count = 0;
    int maxcount = 0;

    set<int> s;

    while (l <= r && r < n)
    {
        if (s.find(str[r]) == s.end()) // if not found in the set
        {
            s.insert(str[r]);
            count++;
            r++;
            maxcount = max(count, maxcount);
        }
        else // if found
        {
            l++; // remove the repetitive element from the window
            count--;

            s.insert(str[r]);

            maxcount = max(count, maxcount);
            count = 1;

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
        cout << SubsequenceLength(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends