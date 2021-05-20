// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

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
    Node *compute(Node *head)
    {
        // BELOW SOLUTION IS CORRECT ONLY IF WE HAVE TO DELETE THE RIGHT BIG NODES ONLY ONCE
        // IN CASE OF REPREATED CHECKING AND REMOVING, THIS SOLUTION FAILS.
        /*
        
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* curr = head;
        Node* prev = NULL;
        while(curr->next!=NULL){
            if(curr->next->data > curr->data){
                // handle this edge case of curr being the head node, separately
                // will occur if the element to be removed is the first element of the list
                if(curr == head || prev == NULL){
                    Node* next = curr->next;
                    curr->next = NULL;
                    curr = next;
                    prev = curr;
                    head = curr;
                    continue;
                }
                else{
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                    continue;
                }
            }
            prev = curr;
            if(curr->next!=NULL)
                curr=curr->next;
        }
        
            return head;
        */

        // BELOW SOLUTION WORKS FOR ALL CASES (RECURSION!)
        if (head->next == NULL)
            return head;

        Node *temp = compute(head->next);

        if (head->data < temp->data)
        {
            return temp;
        }
        else
        {
            head->next = temp;
            return head;
        }

        // BELOW APPROACH IS ALSO CORRECT
        // Kind of a O(n^2) approach since we are setting curr to head every time
        /*
        
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        
        Node *curr = head;
        Node *prev = NULL;
        while (curr && curr->next)
        {
            if (curr->data < curr->next->data)
            {
                prev = curr->next;
                // curr->data = prev->data;
                curr->next = prev->next;
                curr = head;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
        
        */
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
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}