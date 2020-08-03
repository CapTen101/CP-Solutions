// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string str)
{
    // Your code goes here
    int n = str.length();

    int l = 0;
    int r = 0;
    int count = 0;

    set<int> s;

    while (l <= r)
    {
        // if (s.find(str[r]) == s.end())
        // {
        // }

        // if (r == 0)
        // {
        //     s.insert(str[r]);
        //     r++;
        //     count++;
        // }

        if (s.find(str[r]) == s.end()) // if not found in the set
        {
            s.insert(str[r]);
            r++;
            count++;
        }
        else // if found
        {
            l = r;
        }
    }
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