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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *moveLastToFirst(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *curr = head;
        Node *lastNode = NULL;
        Node *secondLastNode = NULL;

        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        secondLastNode = curr;
        lastNode = curr->next;

        // end the linked list
        secondLastNode->next = NULL;

        lastNode->next = head;
        head = lastNode;

        return head;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node *result = ob.moveLastToFirst(head);
        print(result);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends