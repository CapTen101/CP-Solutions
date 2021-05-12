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
Node *removeDuplicates(Node *root);
int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

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

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return head;
    // your code goes here
    Node *it = head;
    while (it->next != NULL)
    {
        if (it->data == it->next->data)
        {
            Node *nextNode = it->next->next;
            it->next->next = NULL;
            it->next = nextNode;
            continue;
        }
        if (it->next != NULL)
            it = it->next;
    }

    return head;
}