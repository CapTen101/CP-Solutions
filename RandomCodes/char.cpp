#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define for (i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int arr[4];

int main()
{
    // {
    //     map<int, int> m;
    //     m.insert({1, 2});
    //     cout << ++m[1];

    //     string s;
    // cout << arr[0] << " " << 23;

    // vector<int> v = {1, 2, 3};
    // cout << v[0] << endl;
    // v.erase(v.begin() + 0);
    // cout << v[0] << endl;

    // string s;
    // s.push_back('1');
    // s.push_back('2');

    unordered_map<int, int> mp;

    mp.insert(make_pair(83, 1));

    if (mp[83])
        cout << "Present" << endl;
    else
        cout << "not Present" << endl;
}