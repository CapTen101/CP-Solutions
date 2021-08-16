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

void inOrder(TreeNode *root, vector<int> &nodes)
{
    if (!root)
        return;

    inOrder(root->left, nodes);
    nodes.push_back(root->val);
    inOrder(root->right, nodes);
}

TreeNode *constructBST(vector<int> &nodes, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    TreeNode *root = new TreeNode(nodes[mid]);
    root->left = constructBST(nodes, left, mid - 1);
    root->right = constructBST(nodes, mid + 1, right);

    return root;
}

TreeNode *balanceBST(TreeNode *root)
{
    if (!root)
        return root;

    vector<int> nodes;
    inOrder(root, nodes);

    return constructBST(nodes, 0, nodes.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}