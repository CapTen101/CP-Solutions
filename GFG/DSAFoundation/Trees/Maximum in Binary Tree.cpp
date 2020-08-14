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

int maxelement(Node *root, int maxnode)
{
    if (root == NULL)
        return INT_MIN;

    maxnode = max(maxnode, root->data);

    return maxelement(root->left, maxnode);
    return maxelement(root->right, maxnode);

    //another way below:
    /*
    if(root==NULL) return;

    else
        return max(root -> data, max(maxelement(root->right), maxelement(root->left)));
    */
}

int main()
{
    ios_base::sync_with_stdio(false);
}