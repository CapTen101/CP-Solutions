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

// another awesome solution: https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/750068/Simple-DFS-python-with-drawing-explanation

/*
pretty weird definition of width of binary tree
max_width is not the max distance between the right-most and left-most nodes, instead, it's the max number of nodes across all levels. 
*/

int getMaxWidth_wrong(TreeNode *root, int level)
{
    if (root == NULL || level == 1)
        return 1;

    return getMaxWidth_wrong(root->right, level - 1) + getMaxWidth_wrong(root->left, level - 1);
}

void depth(TreeNode *root, int level, int &ht)
{
    if (root == NULL)
        return;

    level++;
    if (level > ht)
        ht++;

    if (root->left || root->right)
    {
        depth(root->right, level, ht);
        depth(root->left, level, ht);
    }
}

void getMaxWidth(TreeNode *root, int level, unsigned int column, vector<pair<unsigned int, unsigned int>> &nodes)
{
    if (root == NULL)
        return;

    // saving left-most column value of a particular level
    nodes[level].first = min(nodes[level].first, column);

    // saving right-most column value of a particular level
    nodes[level].second = max(nodes[level].second, column);

    getMaxWidth(root->left, level + 1, 2 * column, nodes);
    getMaxWidth(root->right, level + 1, 2 * column + 1, nodes);
}

int widthOfBinaryTree(TreeNode *root)
{
    // correct solution acc to the definition of 'width' but giving wrong answer since we need to to also include the null nodes between the end nodes of a level
    /*
        int height = 0;
        depth(root, 0, height);
        
        int width = INT_MIN;
        for(int i=1; i<=height; i++)
        {
            width = max(width, getMaxWidth(root, i));
        }
        
        return width;
        */

    int height = 0;
    depth(root, 0, height);
    vector<pair<unsigned int, unsigned int>> nodes(height, {INT_MAX, 0});

    getMaxWidth(root, 0, 0, nodes);
    unsigned int maxWidth = 0;
    for (auto i : nodes)
    {
        maxWidth = max(maxWidth, i.second - i.first + 1);
    }

    return maxWidth;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}