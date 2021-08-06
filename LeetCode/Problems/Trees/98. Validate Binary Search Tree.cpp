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

// inorder traversal -> order must always be increasing -> thus validBST
/*
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
        
        while(s.empty() == false || root!=NULL)
        {
            while(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            if(prev!=NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
            s.pop();
        }
        
        return true;
    }
    */
bool dfs(TreeNode *root, long long small, long long big)
{
    if (root == NULL)
        return true;
    if (root->val <= small or root->val >= big)
        return false;

    long long leftBig = min(big, (long long)root->val);
    long long rightSmall = max(small, (long long)root->val);

    return dfs(root->left, small, leftBig) and dfs(root->right, rightSmall, big);
}

bool isValidBST(TreeNode *root)
{
    const long long inf = INT_MAX * 2LL;
    return dfs(root, -inf, inf);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}