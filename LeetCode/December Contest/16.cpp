#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)

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

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (root->right != NULL && root->left != NULL)
        {
            if (root->right->val > root->val && root->left->val < root->val)
                return isValidBST(root->right) && isValidBST(root->left);
            else
                return false;
        }
        else
        {
            if (root->right == NULL && root->left != NULL)
            {
                if (root->left->val < root->val)
                    return isValidBST(root->left);
                else
                    return false;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                if (root->right->val > root->val)
                    return isValidBST(root->right);
                else
                    return false;
            }
            else
                return true;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}