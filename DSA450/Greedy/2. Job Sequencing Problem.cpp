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
    return (j1.profit > j2.profit);
}

class Solution
{
public:
    vector<int> JobScheduling(Job jobs[], int n)
    {
        vector<int> ans(2);
        int slots = 0;
        int maxdead;

        for (int i = 0; i < n; i++)
            slots = max(slots, jobs[i].dead);

        vector<int> schedule(slots, -1);

        sort(jobs, jobs + n, compare);

        int countjobs = 0, profit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i].dead - 1; j >= 0; j--)
            {
                if (schedule[j] == -1)
                {
                    countjobs++;
                    schedule[j] = jobs[i].id;
                    profit += jobs[i].profit;
                    break;
                }
            }
        }

        ans[0] = countjobs;
        ans[1] = profit;

        return ans;
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