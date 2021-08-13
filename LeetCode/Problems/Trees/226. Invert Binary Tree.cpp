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

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;

    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;
    invertTree(root->right);
    invertTree(root->left);

    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}