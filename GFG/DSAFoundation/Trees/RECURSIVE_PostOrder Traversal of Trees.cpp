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

void postorder(Node *root)
{
    if (root == NULL)
        return;

    return postorder(root->left);
    return postorder(root->right);
    cout << root->data;
}

int main()
{
    ios_base::sync_with_stdio(false);
}