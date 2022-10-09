/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    void MorrisTraversal(TreeNode* root, vector<int> &v)
    {
        TreeNode* curr = root;
        
        while(curr)
        {
            if(curr->left==NULL)
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* temp = curr->left;
                
                while(temp->right && temp->right!=curr)
                {
                    temp = temp->right;
                }
                
                if(!temp->right)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    temp->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        MorrisTraversal(root,v);
        
        int s = 0;
        int e = v.size()-1;
        
        while(s<e)
        {
            if(v[e]+v[s]==k)
                return true;
            if(v[e]+v[s]>k)
                e--;
            else
                s++;
        }
        
        return false;
    }
};
// @lc code=end

