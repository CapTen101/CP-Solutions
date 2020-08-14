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

    return inorder(root->left);
    cout << root->data;
    return inorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
}