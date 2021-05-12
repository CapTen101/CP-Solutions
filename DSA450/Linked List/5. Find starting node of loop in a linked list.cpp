// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

Node *findStart(Node *head, Node *match)
{
    Node *s = head;
    Node *f = match;

    while (f != s)
    {
        s = s->next;
        f = f->next;
    }

    if (f == s)
        return f;
}

void removeLoop(Node *&loopstart)
{
    Node *s = loopstart;
    Node *f = loopstart;

    while (s->next != f)
    {
        s = s->next;
    }
    s->next = NULL;
}

class Solution
{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes

        Node *s = head;
        Node *f = head;
        Node *loopStart = NULL;

        while (f != NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;

            if (f == s)
            {
                // find starting of the loop
                s = head;
                while (f != s)
                {
                    s = s->next;
                    f = f->next;
                }

                Node *loopStartingNode = s; // or f, both are pointing to same node
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
// } Driver Code Ends