/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        int val = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
                TreeNode* frontnode = q.front();
                q.pop();
                
                if(i==0)
                    val = frontnode->val;
                
                if(frontnode->left)
                    q.push(frontnode->left);
                if(frontnode->right)
                    q.push(frontnode->right);
            }
        }
        
        return val;
    }
};
// @lc code=end

