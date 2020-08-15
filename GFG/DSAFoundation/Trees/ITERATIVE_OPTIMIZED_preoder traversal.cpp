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
    Node *current = root;

    while (current != NULL || s.empty())
    {
        while (current != NULL)
        {
            cout << current->data << " ";
            if (current->right != NULL)
                s.push(current->right);
            current = current->left;
        }
        if (s.empty() == false)
        {
            current = s.top();
            s.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
}