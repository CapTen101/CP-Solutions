#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

vector<vector<int>> performOps(vector<vector<int>> &A)
{
    vector<vector<int>> B;
    B.resize(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++)
        {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<vector<int>> B = performOps(A);
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[i].size(); j++)
            cout << B[i][j] << " ";
    }
}