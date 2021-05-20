// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    // time complexity: O(n)
    // space complexity: O(len/k + len%k)
    // the number inside O of space complexity is the number of times recursive call will be made
public:
    struct node *reverse(struct node *head, int k)
    {
        int val = k;

        node *next = NULL;
        node *prev = NULL;
        node *curr = head;

        while (val > 0 && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            val--;
        }

        if (curr != NULL)
        {
            head->next = reverse(curr, k);
        }

        return prev;
    }
};

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}