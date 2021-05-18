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

// NAIVE APPROACH : O(n^3) time and O(1) space
int countTriplets(struct Node *head, int x)
{
    struct Node *ptr1, *ptr2, *ptr3;
    int count = 0;

    // generate all possible triplets
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)

                // if elements in the current triplet sum up to 'x'
                if ((ptr1->data + ptr2->data + ptr3->data) == x)

                    // increment count
                    count++;

    // required count of triplets
    return count;
}

// SECOND APPROACH IS HASHING, with O(n^2) time and O(n) space
// THIRD EFFICIENT APPROACH: TWO POINTERS

// function to count pairs whose sum equal to given 'value' in a range of first pointer to second pointer
int countPairs(struct Node *first, struct Node *second, int value)
{
    int count = 0;

    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while (first != NULL && second != NULL &&
           first != second && second->next != first)
    {

        // pair found
        if ((first->data + second->data) == value)
        {
            count++;

            // first in forward direction
            first = first->next;

            // second in backward direction
            second = second->prev;
        }

        // if sum is greater than 'value'
        // move second in backward direction
        else if ((first->data + second->data) > value)
            second = second->prev;

        // else move first in forward direction
        else
            first = first->next;
    }

    return count;
}

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node *head, int x)
{
    if (head == NULL)
        return 0;

    struct Node *current, *first, *last;
    int count = 0;

    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != NULL)
        last = last->next;

    // main work here
    for (current = head; current != NULL; current = current->next)
    {
        // for each current node
        // so it's basically ( current <-> ... first ... <-> last )
        first = current->next;

        // count pairs with sum(x - current->data) in the range first to last
        // and add it to the 'count' of triplets
        count += countPairs(first, last, x - current->data);
    }

    // count of triplets
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}