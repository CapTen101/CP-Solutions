// { Driver Code Starts
//Initial Template for C
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert();

// } Driver Code Ends
//User function Template for C

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(struct Node *head, int n)
{
    if (head == NULL)
        return -1;

    Node *f = head;
    Node *s = head;

    int val = n;
    while (val > 0)
    {
        if (f == NULL)
            return -1;
        f = f->next;
        val--;
    }

    while (f != NULL)
    {
        f = f->next;
        s = s->next;
    }

    return s->data;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        start = NULL;
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        insert(n);
        int res = getNthFromLast(start, k);
        printf("%d\n", res);
    }
    return 0;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}