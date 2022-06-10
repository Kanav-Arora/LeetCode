/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL)
            return NULL;
        ListNode* temp = head;

        while(temp->next!=NULL)
        {
            if(temp->next->val==temp->val)
            {
                ListNode* to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
            }
            else
                temp = temp->next;
        }

        return head;
    }
};
// @lc code=end

