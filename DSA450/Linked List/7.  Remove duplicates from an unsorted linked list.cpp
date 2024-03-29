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
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
            return head;

        Node *prevNode = head;
        Node *nextNode = head->next;
        set<int> s;
        s.insert(prevNode->data);

        while (nextNode != NULL)
        {
            if (s.find(nextNode->data) == s.end()) // if element not found in set
            {
                s.insert(nextNode->data);
            }
            else // if already present
            {
                prevNode->next = nextNode->next;
                nextNode->next = NULL;
                nextNode = prevNode->next;
                continue;
            }
            prevNode = prevNode->next;
            nextNode = nextNode->next;
        }

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
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends