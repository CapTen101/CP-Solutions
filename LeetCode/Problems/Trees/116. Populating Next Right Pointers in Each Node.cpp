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

Node *connect(Node *root)
{
    // queue solution O(n) -> space
    /*
        if (root == NULL)
            return root;

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (i == size - 1)
                    curr->next = NULL;
                else
                    curr->next = q.front();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return root;
        */

    // constant space solution:

    if (root == NULL)
        return root;

    Node *level_start = root;
    while (level_start)
    {
        Node *curr = level_start;
        while (curr)
        {
            if (curr->left)
                curr->left->next = curr->right;
            if (curr->right and curr->next)
                curr->right->next = curr->next->left;

            curr = curr->next;
        }

        level_start = level_start->left;
    }

    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}