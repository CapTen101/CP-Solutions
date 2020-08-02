
#include <bits/stdc++.h>
using namespace std;

bool isIsogram(string s);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        cout << isIsogram(s) << endl;
    }
    return 0;
}

bool isIsogram(string str)
{
    //Your code here

    set<int> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (s.find(str[i]) == s.end())
            s.insert(str[i]); // if not in the set
        else if (s.find(str[i]) != s.end())
        {
            return 0;
        }
    }

    return 1;
}