#include <bits/stdc++.h>
using namespace std;

// #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
// #define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
// #define ll long long int
// #define ull unsigned long long int
// #define l long int
// #define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
// const ll mod = 1000000007;

int removeDuplicates(vector<int> &A)
{
    int n = A.size();
    int i = 0; // pointer to traverse
    int copy = 0;
    int countcopy = 0; // count of elements in the new-modified array

    if (n == 1)
        return 0; // we'll remove that element

    while (i < A.size())
    {
        if (A[i] == A[i + 1])
        {
            i++; // main pointer
        }
        else
        {
            A[copy] = A[i]; // marking and storing this element in the starting
            countcopy++;    // counting the count variable
            copy++;
        }
    }

    A.erase(A.begin() + countcopy, A.end());

    return countcopy;
}

int main()
{
    ios_base::sync_with_stdio(false);
}