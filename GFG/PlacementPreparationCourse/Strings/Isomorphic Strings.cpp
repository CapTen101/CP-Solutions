// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        cout << areIsomorphic(s1, s2) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

bool areIsomorphic(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    // int map[MAX_CHARS];
    // memset(map, -1, sizeof(map));

    map<int, int> m;

    for (int i = 0; i < str1.length(); i++)
    {
        if (m.find(str1[i]) == m.end()) // if not already present, then insert
            m.insert(str1[i], str2[i]);
    }
}