/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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

    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        int middle = 0;
        if(count%2!=0)
            middle = (count+1)/2;
        else
            middle = (count/2)+1;

        int i = 1;

        temp  = head;
        while(i<middle)
        {
            i++;
            temp = temp->next;
        }
        return temp;
        
    }
};
// @lc code=end

