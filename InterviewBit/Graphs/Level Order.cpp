#include <bits/stdc++.h>
using namespace std;

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;

    while (q.size())
    {
        vector<int> temp;
        int len = q.size();

        for (int i = 0; i < len; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);

            temp.push_back(node->val);
        }
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}