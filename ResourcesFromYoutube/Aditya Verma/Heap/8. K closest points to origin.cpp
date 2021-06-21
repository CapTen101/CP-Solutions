#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int n = p.size();
        priority_queue<pair<float, int>> maxHeap;
        for(int i=0; i<n; i++){
            maxHeap.push({pow(p[i][0], 2) + pow(p[i][1],2), i});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(maxHeap.size()){
            ans.push_back(p[maxHeap.top().second]);
            maxHeap.pop();
        }
        
        return ans;
    }
};

int main(){
return 0;
}
