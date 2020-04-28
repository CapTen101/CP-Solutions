#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

vector<int> performOps(vector<int> A)
{
    vector<int> B(2 * A.size(), 0);
    for (int i = 0; i < A.size(); i++)
    {
        B[i] = A[i];
        B[i + A.size()] = A[(A.size() - i) % A.size()];
    }
    return B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {5, 10, 2, 1};

    vector<int> B = performOps(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }
}