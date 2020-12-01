#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

// this will extract a token out of the string according to the given key
string extractTokenAtKey(string str, int key)
{
    // using strtok
    // str.c_str() extracts the character array from the string! WOW!
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }

    return (string)s;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return stoi(key1) < stoi(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.get();

    string s[n];

    for (int i = 0; i < n; i++)
        getline(cin, s[i]);

    int key;
    string toReverse, whatOrder;
    cin >> key >> toReverse >> whatOrder;

    pair<string, string> strPair[n];

    for (int i = 0; i < n; i++)
    {
        strPair[i].first = s[i];
        strPair[i].second = extractTokenAtKey(s[i], key);
    }

    if (whatOrder == "numeric")
    {
        sort(strPair, strPair + n, numericCompare);
    }
    else if (whatOrder == "lexicographic")
    {
        sort(strPair, strPair + n, lexicoCompare);
    }

    if (toReverse == "true")
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(strPair[i], strPair[n - i - 1]);
        }
    }

    // Printing the output:
    for (int i = 0; i < n; i++)
    {
        cout << strPair[i].first << endl;
    }
}