// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define prime 3

int strstr(string, string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << strstr(a, b) << endl;
    }
}
// } Driver Code Ends

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */

#define ll long long int

ll createHashValue(string str, int n)
{
    ll result = 0;

    for (int i = 0; i < n; i++)
    {
        result += (ll)(str[i] * (ll)pow(prime, i));
    }
    return result;
}

ll reCalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patlength)
{
    ll newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (ll)(str[newIndex] * (ll)pow(prime, patlength - 1));
    return newHash;
}

bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2)
{
    if (end1 - start1 != end2 - start2)
        return false;

    while (start1 <= end1 && start2 <= end2)
    {
        if (str1[start1] != str2[start2])
            return false;

        start1++;
        start2++;
    }

    return true;
}

int strstr(string s, string x)
{
    if (s.length() < x.length())
        return -1;

    ll strHash = createHashValue(s, x.length());
    ll patHash = createHashValue(x, x.length());

    for (int i = 0; i <= s.length() - x.length(); i++)
    {
        if (patHash == strHash && checkEqual(s, x, i, i + x.length() - 1, 0, x.length() - 1))
            return i;

        if (i < s.length() - x.length())
            strHash = reCalculateHash(s, i, i + x.length(), strHash, x.length());
    }

    return -1;
}