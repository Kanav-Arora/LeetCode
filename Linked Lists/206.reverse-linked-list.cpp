/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverse(ListNode *head, ListNode *&new_head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            new_head = head;
            return head;
        }

        ListNode *n = reverse(head->next, new_head);
        n->next = head;
        head->next = NULL;

        return head;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *new_head = NULL;
        ;

        reverse(head, new_head);

        return new_head;
    }
};
// @lc code=end
