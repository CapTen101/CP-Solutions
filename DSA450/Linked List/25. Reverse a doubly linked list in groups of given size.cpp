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

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLLinSizeOfK(Node *head, int k)
{
    Node *curr = head;
    int val = k;
    while (val > 0 && curr != NULL)
    {
        Node *next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
        val--;
    }

    if (curr != NULL)
    {
        head->next = reverseDLLinSizeOfK(curr, k);
        head->next->prev = head;
    }

    return curr->prev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}