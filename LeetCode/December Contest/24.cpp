#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        // If NULL, then return
        if (head == NULL)
            return head;

        // An iterator node for traversing the LinkedList
        ListNode *it = head;

        // A previous pointer to store the second node of the previous pair
        ListNode *prev = NULL;

        while (it != NULL && it->next != NULL)
        {
            // Front and back pointers for the two nodes of the pair to be swapped
            ListNode *back = it;
            ListNode *front = back->next;

            // Pointing Back node to the node next to Front
            back->next = front->next;

            // If it's te start of the Linked List
            if (prev == NULL)
            {
                front->next = back;
                // point the head to Front since Front is not swapped back
                head = front;
            }
            else
            {
                // If it's not the start of the linkedlist,
                // point the Prev pointer to the Front
                // And, Front pointer to the Back.
                prev->next = front;
                front->next = back;
            }

            // Update the Prev pointer
            prev = back;

            // Shift it to Front and two nodes ahead
            it = front;
            it = it->next->next;
        }

        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}