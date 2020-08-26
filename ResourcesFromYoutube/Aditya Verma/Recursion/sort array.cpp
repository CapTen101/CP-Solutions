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

// 2nd function
void insert(vector<int> &arr, int k) // this function will insert a key into the array onto the right position
{
    //base condition
    if (arr.size() == 0 || arr[arr.size() - 1] <= k)
    {
        arr.push_back(k);
        return;
    }

    int temp = arr[arr.size() - 1]; // saving the last element of the array
    arr.pop_back();                 // popping the last element

    insert(arr, k);
    arr.push_back(temp);
}

// 1st function
void sort(vector<int> &arr) // vector is passed as reference
{
    //base condition
    if (arr.size() == 1) // we'll stop if a single element is passed in function
        return;

    // hypothesis step and induction combined
    int temp = arr[arr.size() - 1]; // save the last value of the array
    arr.pop_back();                 // pop that element
    sort(arr);                      // sort the remaining array

    insert(arr, temp); // now insert that remaining temp element in the appropriate position
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v = {6, 5, 8, 9, 3, 6, 97, 11, 5, 95, 45, 87, 633, 12, 5, 8, 0, 26};
    sort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}