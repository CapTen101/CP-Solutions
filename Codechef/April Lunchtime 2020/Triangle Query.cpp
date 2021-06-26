#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        long n, q, answercount = 0;
        cin >> n >> q;
        vector<pair<long, long>> points(n);
        long L[q], r[q];
        for(long i=0; i<n; i++)
        {
            cin >> points[i].first >> points[i].second;
        }
        for(long i=0; i<q; i++)
        {
            cin >> L[i] >> r[i];
        }

        for(long j=0; j<q; j++)
        {
            for(long i=0; i<n; i++)
            {

                if (points[i].first <= ((L[j] + r[j]) / 2))
                {
                    long unknowny = points[i].first - L[j];

                    if ((points[i].first >= L[j]) && (points[i].second <= unknowny) && (points[i].first <= r[j]))
                    {
                        answercount++;
                    }
                    else
                        continue;
                }
                else
                {
                    long unknowny = r[j] - points[i].first;

                    if ((points[i].first >= L[j]) && (points[i].second <= unknowny) && (points[i].first <= r[j]))
                    {
                        answercount++;
                    }
                    else
                        continue;
                }
            }
            cout << answercount << " ";
            answercount = 0;
        }
    }
}