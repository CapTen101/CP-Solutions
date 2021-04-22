// Problem Statement: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool compare(Job j1, Job j2)
{
    return (j1.dead < j2.dead);
}

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        vector<int> ans(2);
        int jobs = 0;
        int profit = 0;

        sort(arr, arr + n, compare);

        for (int i = 0; i < n; i++)
        {
        }
    }
};

int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}