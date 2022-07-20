/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        int maxWidth=INT_MIN;
        
        while(!q.empty())
        {
            int size = q.size();
            
            long long start;
            long long end;
            
            for(int i=0; i<size; i++)
            {
                pair<TreeNode*,int> frontnode = q.front();
                q.pop();
                
                TreeNode* node = frontnode.first;
                long long ind = frontnode.second;
                
                if(i==0)
                    start = ind;
                
                if(i==size-1)
                    end = ind;
                
                if(node->left)
                    q.push({node->left, 2*ind});
                if(node->right)
                    q.push({node->right, 2*ind+1});
            }
            
            maxWidth = max(maxWidth, int(end-start+1));
        }
        
        return maxWidth;
    }
};
// @lc code=end

