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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p and !q)
        return true;
    if (!p || !q)
        return false;

    return (p->val == q->val) and isSameTree(p->right, q->right) and isSameTree(p->left, q->left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}