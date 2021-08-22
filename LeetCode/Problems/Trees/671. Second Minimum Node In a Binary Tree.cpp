#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode *root, set<int> &nodes)
{
    if (root == NULL)
        return;

    nodes.insert(root->val);

    preOrder(root->left, nodes);
    preOrder(root->right, nodes);
}

int findSecondMinimumValue(TreeNode *root)
{
    set<int> s;
    preOrder(root, s);

    if (s.size() >= 2)
    {
        return *(++s.begin());
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}