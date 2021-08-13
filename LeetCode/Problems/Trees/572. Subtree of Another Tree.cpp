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

bool isEqual(TreeNode *first, TreeNode *second)
{
    if (!first and !second)
        return true;
    if (!first || !second)
        return false;

    return (first->val == second->val) and isEqual(first->left, second->left) and isEqual(first->right, second->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root and !subRoot)
        return true;
    if (!root || !subRoot)
        return false;

    vector<TreeNode *> nodes;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *curr = q.front();
        nodes.push_back(curr);
        q.pop();

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }

    for (auto node : nodes)
    {
        if (isEqual(node, subRoot))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}