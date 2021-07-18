#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        if (n == 0 || W == 0)
            return 0;

        if (wt[n - 1] <= W)
            // only a single change will be there compared to knapsack.
            // change (n-1) to n when the element is picked.
            // Rest all same
            return max(knapSack(n - 1, W, val, wt), (val[n - 1] + knapSack(n, W - wt[n - 1], val, wt)));
        else
            return knapSack(n - 1, W, val, wt);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}