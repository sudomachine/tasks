// https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* n, ListNode* m) {

    if (n && m)
    {
        if (n->val <= m->val)
        {
            ListNode * new_n = new ListNode(n->val, mergeTwoLists(n->next, m));
            return new_n;
        }
        else
        {
            ListNode * new_n = new ListNode(m->val, mergeTwoLists(n, m->next));
            return new_n;
        }
    }

    if (n)
    {
        ListNode * new_n = new ListNode(n->val, mergeTwoLists(n->next, nullptr));
        return new_n;
    }

    if (m)
    {
        ListNode * new_n = new ListNode(m->val, mergeTwoLists(nullptr, m->next));
        return new_n;
    }

    if (!n && !m)
    {
        return nullptr;
    }
}

void print(const ListNode* node)
{
    if (node)
    {
        std::cout << node->val << " ";
        print(node->next);
    }
    else
        std::cout << std::endl;
};

ListNode* create(const std::vector<int>& numbers)
{
    if (numbers.size() == 0)
        return nullptr;

    if (numbers.size() == 1)
        return new ListNode(numbers[0], nullptr);

    int size = numbers.size();
    ListNode* node = new ListNode(numbers[size-1], nullptr);

    for (int i = size-2; i >= 0; i--)
    {
        node = new ListNode(numbers[i], node);
    }
}