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
        return true;

    stack<TreeNode *> s;
    TreeNode *prev = NULL;

    while (s.empty() == false || root != NULL)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        if (prev != NULL && prev->val >= root->val)
            return false;
        prev = root;
        root = root->right;
        s.pop();
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
}