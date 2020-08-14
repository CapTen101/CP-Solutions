#include <bits/stdc++.h>
using namespace std;

#define start \
    int t;    \
    cin >> t; \
    while (t--)

struct Node
{
    int data;
    Node *right;
    Node *left;
};

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root); // push to queue (enqueue)

    while (q.empty() != false)
    {
        Node *current = q.front();
        cout << current->data << " ";
        q.pop(); // take out from the queue(take back from the queue)
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}