/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;

    ListNode* temp = head;

    while(temp!=NULL)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }   

    int s=0, e=v.size()-1;

    while(s<=e)
    {
        if(v[s]!=v[e])
            return false;
        
        s++;
        e--;
    }

    return true;
    }
};
// @lc code=end

