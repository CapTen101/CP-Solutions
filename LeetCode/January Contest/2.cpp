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

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // Below is 1.108 second solution:

        // TreeNode *head = original;     // head of the original tree
        // TreeNode *head_clone = cloned; // head of the cloned tree

        // TreeNode *ans = NULL;

        // stack<TreeNode *> s_orig;
        // stack<TreeNode *> s_clone;
        // s_orig.push(head);
        // s_clone.push(head_clone);

        // while (s_orig.empty() == false && s_clone.empty() == false)
        // {
        //     TreeNode *current = s_orig.top();
        //     TreeNode *current_clone = s_clone.top();

        //     if (current->val == target->val)
        //     {
        //         ans = current_clone;
        //         return current_clone;
        //     }

        //     s_orig.pop();
        //     s_clone.pop();

        //     if (current->right != NULL)
        //     {
        //         s_orig.push(current->right);
        //         s_clone.push(current_clone->right);
        //     }
        //     if (current->left != NULL)
        //     {
        //         s_orig.push(current->left);
        //         s_clone.push(current_clone->left);
        //     }
        // }

        // return ans;

        if (original == target || original == NULL)
            return cloned;

        TreeNode *left = getTargetCopy(original->left, cloned->left, target);

        if (left != NULL)
            return left;

        else
            return getTargetCopy(original->right, cloned->right, target);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}