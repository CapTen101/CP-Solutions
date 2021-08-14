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
    if (!root)
        return root;

    Node *level_start = root;

    while (level_start)
    {
        Node *curr = level_start;
        while (curr)
        {
            // if curr's right and left both exist
            if (curr->left and curr->right)
                curr->left->next = curr->right;
            // if atleast one of them exists
            else if (curr->left || curr->right)
            {
                // if curr's left exists
                if (curr->left and curr->next)
                {
                    if (curr->left and curr->next->left)
                        curr->left->next = curr->next->left;
                    else if (curr->left and curr->next->right)
                        curr->left->next = curr->next->right;
                }
                // if curr's right exists
                else if (curr->right and curr->next)
                {
                    if (curr->right and curr->next->left)
                        curr->right->next = curr->next->left;
                    else if (curr->right and curr->next->right)
                        curr->right->next = curr->next->right;
                }
            }
            // if no child exists, then simply continue to curr's next
            curr = curr->next;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}