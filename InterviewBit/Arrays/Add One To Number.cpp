#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

vector<int> plusOne(vector<int> &A)
{
    vector<int> result, B;

    for (int i = A.size() - 1; i >= 0; i--)
        result.push_back(A[i]);

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == 9)
        {
            result[i] = 0;
            if (i == result.size() - 1)
            {
                result.push_back(1);
                break;
            }

            continue;
        }
        result[i]++;
        break;
    }

    for (int i = result.size() - 1; i >= 0; i--)
        B.push_back(result[i]);

    int nz;

    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == 0)
            continue;

        nz = i;
        break;
    }

    result.clear();

    for (int i = nz; i < B.size(); i++)
        result.push_back(B[i]);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v = {0, 1, 2, 3};
    vector<int> v1 = plusOne(v);
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i];
    cout << endl;
}