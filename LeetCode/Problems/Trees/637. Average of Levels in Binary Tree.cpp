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

vector<vector<long long>> levelOrder(TreeNode *root)
{
    vector<vector<long long>> v;
    if (root == NULL)
        return v;

    queue<TreeNode *> q;
    q.push(root);

    while (q.size())
    {
        int size = q.size();
        vector<long long> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            level.push_back(current->val);

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        v.push_back(level);
    }

    return v;
}

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> ans;

    vector<vector<long long>> v;
    v = levelOrder(root);

    for (int i = 0; i < v.size(); i++)
    {
        long long int sum = v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            sum += v[i][j];
        }
        ans.push_back((double)sum / (double)v[i].size());
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}