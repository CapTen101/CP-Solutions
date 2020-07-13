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

vector<long long> reverseInGroups(vector<long long> mv, int n, int k)
{
    for (int i = 0; i < n; i += k)
    {
        long long left = i;
        long long right = min(i + k - 1, n - 1);

        while (left < right)
        {
            swap(mv[left++], mv[right--]);
        }
    }

    return mv;
}

int main()
{

    int t;    //Testcases
    cin >> t; //input the number of testcases

    while (t--)
    { //while testcases exist

        int n;
        cin >> n; //input the size of array

        vector<long long> mv; // Declaring a vector mv

        int k;
        cin >> k; //input k

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x; //input element of array

            mv.push_back(x); //push the element into vector
        }

        mv = reverseInGroups(mv, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << mv[i] << " "; //Just print the vector
        }

        cout << endl;
    }
}