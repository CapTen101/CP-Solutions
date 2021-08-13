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

bool helper(TreeNode *left, TreeNode *right)
{
    if (!right and !left)
        return true;
    if (!right || !left)
        return false;

    if (right->val != left->val)
        return false;
    else
        return helper(left->right, right->left) && helper(left->left, right->right);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    return helper(root->left, root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}