#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        l n, q, answercount = 0;
        cin >> n >> q;
        vector<pair<l, l>> points(n);
        l L[q], r[q];
        loop(l, i, 0, n)
        {
            cin >> points[i].first >> points[i].second;
        }
        loop(l, i, 0, q)
        {
            cin >> L[i] >> r[i];
        }

        loop(l, j, 0, q)
        {
            loop(l, i, 0, n)
            {
                if (r[j] > L[j])
                {
                    if (points[i].first <= ((L[j] + r[j]) / 2))
                    {
                        l unknowny = points[i].first - L[j];

                        if ((points[i].first >= L[j]) && (points[i].second <= unknowny) && (points[i].first <= r[j]))
                        {
                            answercount++;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        l unknowny = r[j] - points[i].first;

                        if ((points[i].first >= L[j]) && (points[i].second <= unknowny) && (points[i].first <= r[j]))
                        {
                            answercount++;
                        }
                        else
                            continue;
                    }
                }

                else
                {
                    if (points[i].first <= ((L[j] + r[j]) / 2))
                    {
                        l unknowny = points[i].first - r[j];

                        if ((points[i].first >= r[j]) && (points[i].second <= unknowny) && (points[i].first <= L[j]))
                        {
                            answercount++;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        l unknowny = L[j] - points[i].first;

                        if ((points[i].first >= r[j]) && (points[i].second <= unknowny) && (points[i].first <= L[j]))
                        {
                            answercount++;
                        }
                        else
                            continue;
                    }
                }
            }
            cout << answercount << " ";
        }
    }
}