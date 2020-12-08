#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        vector<pair<int, Node *>> list;
        queue<pair<int, Node *>> q;
        q.push({0, root});
        list.push_back({0, root});

        while (q.empty() == false)
        {
            pair<int, Node *> p = q.front();
            Node *node = p.second;
            int currentLevel = p.first;
            q.pop();
            currentLevel++;

            if (node->left != NULL)
            {
                q.push({currentLevel, node->left});
                list.push_back({currentLevel, node->left});
            }

            if (node->right != NULL)
            {
                q.push({currentLevel, node->right});
                list.push_back({currentLevel, node->right});
            }
        }

        for (int i = 0; i < list.size(); i++)
        {
            if (i == list.size() - 1)
                break;

            if (i == 0)
                continue;

            if (list[i].first == list[i + 1].first)
                list[i].second->next = list[i + 1].second;
            else
                list[i].second->next = NULL;
        }

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}