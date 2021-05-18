// { Driver Code Starts
/* Program to split a circular linked list into two halves */
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

/* structure for a Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;
        }

        temp->next = head;

        splitList(head, &head1, &head2);

        // printf("\nFirst Circular Linked List");
        printList(head1);

        // printf("\nSecond Circular Linked List");
        printList(head2);
    }
    return 0;
}

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if (head == NULL)
    {
        head1_ref = &head;
        head2_ref = &head;
    }

    Node *f = head;
    Node *s = head;

    while (f->next != head && f->next->next != head)
    {
        f = f->next->next;
        s = s->next;
    }

    // now f points to last node or second last node
    // check for them
    if (f->next == head) // if true, then there are odd no. of elements in the circular list
    {
        f->next = s->next;
        s->next = head;
        *head1_ref = head;    // REMEMBER: this double pointer thing. asterisk * will come while assigning
        *head2_ref = f->next; // make the next node of s to be the head of next list
    }
    else if (f->next->next == head) // if true, then there are even no. of elements in the circular list
    {
        f = f->next; // now f points to last node in list
        f->next = s->next;
        s->next = head;
        *head1_ref = head;    // REMEMBER: this double pointer thing. asterisk * will come while assigning
        *head2_ref = f->next; // make the next node of s to be the head of next list
    }
}