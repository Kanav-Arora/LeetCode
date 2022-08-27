/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      bool isPalindrome(string s) {
        int st = 0;
        int e = s.length()-1;
        
        while(st<e)
        {
            if(!isalnum(s[st]))
                st++;
            else if(!isalnum(s[e]))
                e--;
            else if(tolower(s[st])!=tolower(s[e]))
                return false;
            else
            {
                st++;
                e--;
            }
        }
        
        return true;
    }
};
// @lc code=end

