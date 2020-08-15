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

void inorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (s.empty() == false)
    {
        Node *current = s.top();
        cout << current->data;
        s.pop();
        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}