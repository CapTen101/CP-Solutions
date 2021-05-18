#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *fir, struct Node *sec)
    {
        Node *curr = fir, *prev = NULL, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *f = prev;

        // reversing the second list
        curr = sec, prev = NULL, next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *s = prev;

        // Now main work starts
        int carry = 0;

        // Making the head of a new linked list
        Node *sumHead = new Node(-1);
        Node *sumCurr = sumHead;

        while (f != NULL || s != NULL)
        {
            if (f == NULL || s == NULL)
            {

                if (f == NULL && s == NULL)
                {
                    if (carry == 0)
                        break;
                    if (carry > 0)
                    {
                        sumCurr->next = new Node(carry);
                        sumCurr = sumCurr->next;
                    }
                }
                else if (s == NULL && f != NULL)
                {
                    int value = f->data + carry;
                    sumCurr->next = new Node(value % 10);
                    carry = value / 10;
                    sumCurr = sumCurr->next;
                    f = f->next;
                    continue;
                }

                else if (f == NULL && s != NULL)
                {
                    int value = s->data + carry;
                    sumCurr->next = new Node(value % 10);
                    carry = value / 10;
                    sumCurr = sumCurr->next;
                    s = s->next;
                    continue;
                }
            }

            int value = f->data + s->data + carry;
            sumCurr->next = new Node(value % 10);
            carry = value / 10;
            sumCurr = sumCurr->next;
            f = f->next;
            s = s->next;
        }

        // now reverse the linked list again, to get original added number
        curr = sumHead->next, prev = NULL, next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}