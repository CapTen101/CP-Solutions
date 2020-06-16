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
    int size = A.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (A[i] == 9)
        {
            A[i] = 0;
            continue;
        }
        A[i]++;
        break;
    }

    int nz;

    for (int i = 0; i < size; i++)
    {
        if (A[i] == 0)
            continue;

        nz = i;
        break;
    }
    vector<int> B;
    for (int i = nz; i < size; i++)
    {
        B.push_back(A[i]);
    }
    return B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v = {9, 9};
    vector<int> v1 = plusOne(v);
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i];
    cout << endl;
}