/*
A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
Generally, Heaps can be of two types:

Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present 
at all of it’s children. The same property must be recursively true for all sub-trees in that 
Binary Tree. (MAX AT TOP)

Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present 
at all of it’s children. The same property must be recursively true for all sub-trees in that 
Binary Tree. (MIN AT TOP)

IDENTIFICATION:

- contains k size of something
- smallest/largest

IF GIVEN:
- k + smallest -> maxHeap
- k + largest -> minHeap

Mostly questions of heap are children questions of sorting section. 
All Heap questions can be done with sorting O(nLogn).
But with Heap, it can be reduced to O(nLogk).

By-default, priority_queue is maxHeap, and reverse is minHeap.

Syntax:
- priority_queue<int> maxHeap; => maxHeap
- priority_queue<int, vector<int>, greater<int>> minHeap; => minHeap

If a pair needs to be stored in heap, then replace 'int' with 'pair<int, int>' in above syntax 
*/
#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)
typedef pair<int, pair<int, int>> ppi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
}