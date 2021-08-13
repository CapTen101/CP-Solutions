#include <bits/stdc++.h>
using namespace std;

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int a = 0; // count of no swaps
    int b = 1; // count of swaps
    for (int i = 1; i < nums1.size(); i++)
    {
        int p1 = 1000000, p2 = 1000000, p3 = 1000000, p4 = 1000000;
        if ((nums1[i] > nums1[i - 1]) && (nums2[i] > nums2[i - 1])) // previous no swap now no swap -> about -> (i-1, i)
        {
            p1 = a;
        }
        if ((nums1[i] > nums2[i - 1]) && (nums2[i] > nums1[i - 1])) // previous swap now no swap
        {
            p2 = b;
        }
        if ((nums1[i] > nums2[i - 1]) && (nums2[i] > nums1[i - 1])) // previous no swap now swap
        {
            p3 = a + 1;
        }
        if ((nums1[i] > nums1[i - 1]) && (nums2[i] > nums2[i - 1])) // previous swap now swap
        {
            p4 = b + 1;
        }
        a = min(p1, p2);
        b = min(p3, p4);
    }
    return min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}