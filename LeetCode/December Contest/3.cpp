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
const ll mod = 1000000007;

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
    // This list will keep all the values in increasing order from the BST
    vector<int> list;

    // This function will traverse the tree in In-Order fashion
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        // Pupolate the 'list' vector with values from BST
        inorder(root);

        // Iterator index to traverse the vector
        int index = 0;

        // Initialise the first node 'newRoot' of the new tree
        TreeNode *newRoot = new TreeNode(list[index]);
        TreeNode *current = newRoot;

        while (index < list.size())
        {
            index++;

            // Exit the loop if the end of the vector is reached
            if (index >= list.size())
                break;

            // Make a new right node and initialize it
            current->right = new TreeNode(list[index]);

            // Move on to that right node
            current = current->right;
        }

        // return the new root
        return newRoot;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}