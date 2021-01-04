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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *curr = new ListNode();
        ListNode *head = curr;

        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        while (l1 && l2)
        {
            if (l2 == NULL || l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        if ((l1 && !l2) || (!l1 && l2))
        {
            if (l2)
                curr->next = l2;
            else
                curr->next = l1;
        }

        return head->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
}