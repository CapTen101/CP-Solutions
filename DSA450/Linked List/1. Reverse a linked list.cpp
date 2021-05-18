#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
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

void reverseUtil(struct Node *head)
{
}

class Solution
{
public:
    //Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        // ITERATIVE METHOD
        Node *curr = head, *prev = NULL, *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev; // reversing the link backwards
            prev = curr;
            curr = next;
        }
        return prev;

        // RECURSIVE METHOD
        if (head == NULL || head->next == NULL)
            return head;

        Node *tempNode = reverseList(head->next);
        head->next->next = head; // V. IMP
        // basically it goes from 1 -> (2 <- 3 <- 4) ....=> TO => (1 <- 2 <- 3 <- 4) .....
        head->next = NULL;
        return tempNode;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends