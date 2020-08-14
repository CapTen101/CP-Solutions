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

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data;
    return preorder(root->left);
    return preorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
}