// { Driver Code Starts
//Initial template for C++

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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        if (!head || !N)
            return head;
        // ONE APPROACH is to make two separate lists for edd and even numbers
        // and then merge them. but this method involves memory consumption. bad bad

        // BELOW is my own approach to achieve the same result without extra memory consumption
        // BASICALLY REVERSE AND SHIFT EVEN ELEMENTS
        // 1. reverse the list
        // 2. now check for numbers.
        //    - if even: shift the node to last of reverse list (or in other words to start of original list)
        //    - if odd: the ignore and move forward
        // in the end, reverse the list again and voila! done!
        // BUT THIS APPROACH IS QUITE LENGTHY AND ERROR PRONE AND CURRENTLY NOT WORKING
        // BUT CAN BE HANDY IN EXPLAINING IN INTERVIEW, FOR NOW IGNORE IT!
        /*
        
        Node *curr = head, *prev = NULL, *next = NULL;
        while (curr->next != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *revHead = prev; // head of reversed list, original *head still points to first node of original list
        curr = revHead;       // start from the start of reversed list
        prev = NULL;          // maintain a previous node as well
        Node* shift = NULL;

        while (curr->next != NULL && N--)
        {
            if ((curr->data % 2) == 0) // if even
            {
                if (curr == revHead)
                {
                    // cout<<"data="<<head->data<<" ";
                    shift = curr; // store this node which will be shifted to last
                    curr = curr->next;  // move on to next
                    revHead = curr;     // store the new head of reversed list
                    shift->next = NULL;
                    head->next = shift; // attach the node to the end of reversed list (use *head for that)
                    head = head->next;  // reassign head to point to last node
                    head->next = NULL;
                }
                else
                {
                    // cout<<"data="<<head->data<<" ";
                    if (prev == NULL)
                        prev = revHead;
                    prev->next = curr->next; // skip the *curr node
                    curr->next = NULL;
                    head->next = curr; // attach the node to the end of reversed list (use *head for that)
                    head = head->next; // reassign head to point to last node
                    curr = prev->next;
                }
            }
            else
            {
                // if odd, then ignore
                // cout<<"data="<<head->data<<" ";
                prev = curr;
                curr = curr->next;
            }
               
        }

        // now finally reverse the list:
        curr = revHead, prev = NULL, next = NULL;
        while (curr->next != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
        */

        Node *last = head, *curr = head, *prev = NULL;
        while (last->next)
        {
            // point this node to last
            last = last->next;
        }

        while (curr->next != NULL && N--)
        {
            if ((curr->data) % 2 != 0) // if odd, then shift to last
            {
                if (curr == head) // take care of this edge case
                {
                    head = head->next;
                    curr->next = NULL;
                    last->next = curr;
                    last = last->next;
                    curr = head;
                }
                else
                {
                    prev->next = curr->next;
                    curr->next = NULL;
                    last->next = curr;
                    last = last->next;
                    curr = prev->next;
                }
            }
            else // if even, ignore
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

// { Driver Code Starts.

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends