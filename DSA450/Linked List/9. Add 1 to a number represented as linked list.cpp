#include <bits/stdc++.h>
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        if (head == NULL)
            return head;

        Node *curr = head;

        // Reverse the linked list:
        Node *prev = NULL, *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev; // reversing the link backwards
            prev = curr;
            curr = next;
        } // prev is the reversed head
        Node *revHead = prev;

        Node *revcurr = revHead;
        cout << "revcurr: " << revcurr->data << endl;
        int carry = 0;
        while (revcurr != NULL)
        {
            if (revcurr->data <= 8)
            {
                revcurr->data = revcurr->data + 1;
                break;
            }
            else
            {
                revcurr->data = 0;
                carry = 1;
            }

            // insert a new node if all elements are 9. for ex: 99, 1299, ...
            if (revcurr->next == NULL && carry == 1)
            {
                revcurr->next = new Node(1);
                revcurr = revcurr->next;
                break;
            }

            revcurr = revcurr->next;
        }

        // Now, reversing again to put the number in original order:
        curr = revHead;
        prev = NULL;
        next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev; // reversing the link backwards
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
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends