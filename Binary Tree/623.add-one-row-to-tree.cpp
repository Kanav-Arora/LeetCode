/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* solver(TreeNode* root, int val, int depth, int k)
    {
        if(root==NULL)
            return root;
        
        if(k==depth-1)
        {
            TreeNode* lt = new TreeNode(val);
            lt->left = root->left;
            root->left = lt;
            
            TreeNode* rt = new TreeNode(val);
            rt->right = root->right;
            root->right = rt;
            
            return root;
        }
        
        root->left = solver(root->left,val,depth,k+1);
        root->right = solver(root->right,val,depth,k+1);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        return solver(root,val,depth,1);
    }
};
// @lc code=end

