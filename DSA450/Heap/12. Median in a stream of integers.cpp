#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    priority_queue<int> ma; // maxHeap
    priority_queue<int, vector<int>, greater<int>> mi; // minHeap
    
    void insertHeap(int &x)
    {
        // insert first element
        if(!ma.size()){
            ma.push(x);
            return;
        }
        
        // if there's atleast one element in maxHeap then
        // compare x with the top_ele of maxHeap
        if(x < ma.top()){
            ma.push(x);
        }
        else
            mi.push(x);
            
        balanceHeaps();
    }
    
    //Function to balance
    // that is, make both heap's size equal or at most 1 element difference
    void balanceHeaps()
    {
        if(abs(ma.size() - mi.size()) >= 2){
            if(ma.size() > mi.size()){
                int shift_ele = ma.top();
                ma.pop();
                mi.push(shift_ele);
            }
            else{
                int shift_ele = mi.top();
                mi.pop();
                ma.push(shift_ele);
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(ma.size() == mi.size()){
            return (ma.top() + mi.top())/2.0;
        }
        else if(ma.size() > mi.size()){
            return ma.top();
        }
        else
            return mi.top();
    }
};

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
