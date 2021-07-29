#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

private:
    int data;
    TreeNode *rightChild;
    TreeNode *leftChild;

public:
    void fillInLevel(int level);

    int getData()
    {
        return data;
    }

    TreeNode *getRC()
    {
        return rightChild;
    }

    TreeNode *getLC()
    {
        return leftChild;
    }

    void setRC(TreeNode *node)
    {
        rightChild = node;
    }

    void setLC(TreeNode *node)
    {
        leftChild = node;
    }

    TreeNode(int value)
    {
        data = value;
        rightChild = NULL;
        leftChild = NULL;
    }
};

class Tree
{
public:
    TreeNode *root;
    Tree(TreeNode *node)
    {
        root = node;
    }

    void helper(TreeNode *root, int i, int level)
    {
        if (level == i)
            return;

        if (root->getRC() == NULL)
        {
            TreeNode *temp = new TreeNode(-1);
            root->setRC(temp);
        }
        if (root->getLC() == NULL)
        {
            TreeNode *temp = new TreeNode(-1);
            root->setLC(temp);
        }

        helper(root->getLC(), i + 1, level);
        helper(root->getRC(), i + 1, level);
    }

    void fillInLevel(int level)
    {
        TreeNode *temp = root;
        helper(root, 0, level);
    }
};

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->getData() << " ";
    preorder(root->getLC());
    preorder(root->getRC());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(1);

    TreeNode *temp_r1 = new TreeNode(2);
    root->setRC(temp_r1);

    TreeNode *temp_r2 = new TreeNode(3);
    root->getRC()->setRC(temp_r2);

    Tree *tree = new Tree(root);

    tree->fillInLevel(2);

    preorder(root);

    cout << endl;
}