#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isUnivalTree(TreeNode *root)
{
    if (root == NULL)
        return true;

    bool condition = true;
    if (root->left)
    {
        condition = (root->val == root->left->val);
        if (!condition)
            return false;
    }
    if (root->right)
    {
        condition = (root->val == root->right->val);
        if (!condition)
            return false;
    }

    return condition and isUnivalTree(root->left) and isUnivalTree(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}