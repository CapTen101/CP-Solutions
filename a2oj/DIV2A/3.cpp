#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    queue<int> q;

    loop(int, i, 0, s.length())
    {
        q.push(s[i]);
    }

    vector<char> ch = {'a', 'b', 'c'};


    loop(int, i, 0, s.length())
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'e' || s[i] == 'u')
    }
}