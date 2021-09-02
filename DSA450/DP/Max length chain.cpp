#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}

bool compare(val &v1, val &v2) { return v1.first < v2.first; }

int maxChainLen(val p[], int n)
{
    sort(p, p + n, compare);
    vector<int> dp(n, 1);
    if (n == 1)
        return 1;

    int max_len = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[j].second < p[i].first and dp[i] <= dp[j])
                dp[i] = 1 + dp[j];

            max_len = max(max_len, dp[i]);
        }
    }

    return max_len;
}