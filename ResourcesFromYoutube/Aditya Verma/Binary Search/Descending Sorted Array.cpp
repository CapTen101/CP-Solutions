/*
Let's suppose that we have an array sorted in descending order and we want to find index of an element e within this 
array. Binary search in every step picks the middle element (m) of the array and compares it to e. If these elements 
are equal, than it returns the index of m. If e is greater than m, than e must be located in the left subarray. On the 
contrary, if m greater than e, e must be located in the right subarray. At this moment binary search repeats the step 
on the respective subrarray.

 Because the algoritm splits in every step the array in half (and one half of the array is never processed) the input 
 element must be located (or determined missing) in at most log_{2}{n} steps.
*/

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

int binary(int a[], int leftIndex, int rightIndex, int value)
{
    while (leftIndex < rightIndex)
    {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        if (value == a[mid])
        {
            return mid;
        }
        else if (value > a[mid])
        {
            rightIndex = mid - 1;
        }
        else if (value < a[mid])
        {
            leftIndex = mid + 1;
        }
    }

    return -1;
}

// no need for implementing the complete program. function is enough
int main()
{
    ios_base::sync_with_stdio(false);
}