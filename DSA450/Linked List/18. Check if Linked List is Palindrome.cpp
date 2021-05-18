#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution
{
public:
    // Apply concept of finding middle element.
    // using fast/slow pointer as used in middle element question
    // then reverse the second half of list
    // compare the two lists
    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        if (head->next->next == NULL)
        {
            return (head->data == head->next->data ? true : false);
        }

        Node *s = head;
        Node *f = head;

        while (f->next != NULL && f->next->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }

        if (f->next == NULL) // list has ODD no. of elements
        {
            f = s->next;
            // reversing the list starting from f
            Node *curr = f, *prev = NULL, *next = NULL;
            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            f = prev;

            // moving s to start and now start comparing s & f
            s = head;
            while (s->next->next != f)
            {
                if (s->data != f->data)
                    return false;
                s = s->next;
                f = f->next;
            }

            if (s->data != f->data)
                return false;
        }
        else if (f->next->next == NULL) // list has EVEN no. of elements
        {
            f = s->next;
            // reversing the list starting from f
            Node *curr = f, *prev = NULL, *next = NULL;
            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            f = prev;

            // moving s to start and now start comparing s & f
            s = head;
            while (s->next != f)
            {
                if (s->data != f->data)
                    return false;
                s = s->next;
                f = f->next;
            }

            if (s->data != f->data)
                return false;
        }

        return true;
    }
};

int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends