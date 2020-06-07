#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; ++x)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int main()
{
    // string s = "hacker";
    // int k = 2;
    // string newstring;
    // newstring.resize(s.length());

    // loop(int, i, 0, s.length())
    // {
    //     newstring[(i + k) % s.length()] = s[i];
    // }

    // newstring[s.length()] = '\0';
    // cout << newstring;

    // unsigned ll i = INT_MAX;
    // cout << i;
    string s;
    getline(cin, s);
    cout << s;
}