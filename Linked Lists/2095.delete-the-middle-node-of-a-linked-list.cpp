/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode *deleteMiddle(ListNode *head)
    {
        int count(ListNode * head)
        {
            int cnt = 0;

            while (head)
            {
                cnt++;
                head = head->next;
            }

            return cnt;
        }

        ListNode *deleteMiddle(ListNode * head)
        {
            if (head == NULL)
                return NULL;

            int cnt = count(head);

            int mid = cnt / 2;
            ListNode *temp = head;
            int i = 1;

            if (mid == 0)
                return head->next;

            while (temp && i < mid)
            {
                i++;
                temp = temp->next;
            }

            ListNode *to_delete = temp->next;
            temp->next = temp->next->next;

            delete to_delete;

            return head;
        }
    }
};
// @lc code=end
