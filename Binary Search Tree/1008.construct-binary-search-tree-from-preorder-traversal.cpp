/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *insertToBST(TreeNode * root, int val)
        {
            if (root == NULL)
            {
                root = new TreeNode(val);
                return root;
            }

            if (val > root->val)
                root->right = insertToBST(root->right, val);
            else
                root->left = insertToBST(root->left, val);

            return root;
        }

        TreeNode *bstFromPreorder(vector<int> & preorder)
        {
            TreeNode *root = new TreeNode(preorder[0]);

            if (preorder.size() == 1)
                return root;

            int i = 1;

            while (i < preorder.size() && preorder[i] < preorder[0])
            {
                root->left = insertToBST(root->left, preorder[i]);
                i++;
            }

            while (i < preorder.size())
            {
                root->right = insertToBST(root->right, preorder[i]);
                i++;
            }

            return root;
        }
    }
};
// @lc code=end
