// { Driver Code Starts
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

class Solution
{
public:
    //Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        // Your code here
        Node *last = head;
        int len = 0;
        while (last->next != NULL)
        {
            len++;
            last = last->next;
        }
        len++;       // since last noe is not counted
        k = k % len; // since only the remainder is how much times we need to rotate

        int i = k;
        Node *curr = head;
        while (i > 0)
        {
            head = head->next;
            last->next = curr;
            curr->next = NULL;
            curr = head;
            last = last->next;
            i--;
        }

        return head;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}