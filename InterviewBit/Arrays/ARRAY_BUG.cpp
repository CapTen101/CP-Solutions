#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define l long int
#define pb push_back
#define MOD 1000000007

vector<int> rotateArray(vector<int> &A, int B)
{
    vector<int> ret;
    for (int i = 0; i < A.size(); i++)
    {
        ret.push_back(A[(i + B) % A.size()]);
    }

    // Another Approach for this question 

    // B = B % A.size();
    // reverse(A.begin(), A.begin() + B);
    // reverse(A.begin() + B, A.end());
    // reverse(A.begin(), A.end());
    // return A;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {14, 5, 14, 34, 42, 63, 17, 25, 39, 61, 97, 55, 33, 96, 62, 32, 98, 77, 35};
    vector<int> B(A.size());
    B = rotateArray(A, 56);

    loop(int, i, 0, B.size())
    {
        cout << B.at(i) << endl;
    }
}