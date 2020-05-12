#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define loop(typeofx, x, start, end) for (typeofx x = start; x < end; x++)
#define listTraverse(datatypeoflist, x, startList, endList) for (list<datatypeoflist>::iterator x = startList; x != endList; ++x)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
const ll mod = 1000000007;

int Partition(int *A, int start, int end)
{

    int pivot = A[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}

void QuickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int pIndex = Partition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[] = {1, 5, 2, 9, 4, 4, 0, 6};
    QuickSort(arr, 0, 7);

    loop(int, i, 0, 8) cout << arr[i] << " ";
}