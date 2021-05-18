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

void deleteNode(Node **head, int key)
{

    // If linked list is empty
    if (*head == NULL)
        return;

    // If the list contains only a single node
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head, *d;

    // If head is to be deleted
    if ((*head)->data == key)
    {

        // Find the last node of the list
        while (last->next != *head)
            last = last->next;

        // Point last node to the next of head i.e.
        // the second node of the list
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    // If node to be deleted was found
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "no such keyfound";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}