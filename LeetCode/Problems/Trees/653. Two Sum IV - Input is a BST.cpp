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

void inOrder(TreeNode *root, vector<int> &nodes)
{
    if (!root)
        return;

    inOrder(root->left, nodes);
    nodes.push_back(root->val);
    inOrder(root->right, nodes);
}

bool findTarget(TreeNode *root, int k)
{
    if (!root)
        return false;

    vector<int> nodes;
    inOrder(root, nodes);

    int l = 0, h = nodes.size() - 1;
    while (l < h)
    {
        int val = nodes[l] + nodes[h];
        if (val == k)
            return true;
        else if (k < val)
        {
            h--;
        }
        else
            l++;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}