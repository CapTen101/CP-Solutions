// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*  Function to check if two strings are anagram
*   c, d: input string
*/
// #define CHAR 256

bool isAnagram(string a, string b)
{
    // Your code here
    int n = a.length();
    int m = b.length();

    if (n != m)
        return 0;

    int count[256];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
    {
        // if (.find(b[i]) == s.end())
        //     return 0;
        // else
        // {
        //     if (marked[b[i] - 'a'])
        //         return 0;
        //     else
        //         marked[b[i] - 'a'];
        // }

        count[a[i]]++;
        count[b[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

// { Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;

        if (isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
// } Driver Code Ends