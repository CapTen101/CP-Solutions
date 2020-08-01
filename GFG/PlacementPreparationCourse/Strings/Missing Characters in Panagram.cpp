#include <bits/stdc++.h>
using namespace std;

// A panagram is a string with every letter in the english alphabet present in the string

string missingPanagram(string str);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << missingPanagram(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

//User function Template for C++

string missingPanagram(string str)
{
    string ans;
    //Your code here
    // set<char> s = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<int> v(26, 0);

    for (int i = 0; i < str.length(); i++)
    {
        // if (!(s.find(str[i]) != s.end()))
        //     ans += str[i];

        if ((str[i] >= 'a') && (str[i] <= 'z'))
            v[str[i] - 'a'] = 1;

        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            v[str[i] - 'A'] = 1;
    }

    for (int i = 0; i < 26; i++)
        if (v[i] == 0)
            ans.append(1, char(i + 'a'));

    return ans;
}
