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

void depth(TreeNode *root, int level, int &ht)
{
    if (root == NULL)
        return;

    level++;
    if (level > ht)
        ht++;

    if (root->left || root->right)
    {
        depth(root->right, level, ht);
        depth(root->left, level, ht);
    }
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int height = 0;
    depth(root, 0, height);
    return height;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}