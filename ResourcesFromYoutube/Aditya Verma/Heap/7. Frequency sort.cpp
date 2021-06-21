#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

class Solution {
public:
    string frequencySort(string s) {
//         map<char, int> m;
        
//         for(int i=0; i<s.size(); i++){
//             m[s[i]]++;
//         }
        
//         string ans;
        
//         auto lambda = [&](char a, char b){
//             if(m[a] == m[b]){
//                 return a<b;
//             }  
//             else
//                 return (m[a] > m[b]);
//         };
        
//         sort(s.begin(), s.end(), lambda);
        
//         return s;
        
        // HEAP approach
        string ans="";
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        
        for(auto i = m.begin(); i!=m.end(); i++){
            maxHeap.push({i->second, i->first});
        }
        
        while(maxHeap.size()){
            int freq = maxHeap.top().first;
            char ele = maxHeap.top().second;
            for(int i=0; i<freq; i++){
                ans+=ele;
            }
            maxHeap.pop();
        }
        
        return ans;
    }
};
