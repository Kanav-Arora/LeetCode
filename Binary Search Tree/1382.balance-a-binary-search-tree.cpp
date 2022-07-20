/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    void normalBSttoInorder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;

        normalBSttoInorder(root->left, inorder);
        inorder.push_back(root->val);
        normalBSttoInorder(root->right, inorder);
    }

    TreeNode *inorderToBalanced(vector<int> inorder, int s, int e)
    {
        if (s > e)
            return NULL;

        int mid = s + (e - s) / 2;
        TreeNode *node = new TreeNode(inorder[mid]);
        node->left = inorderToBalanced(inorder, s, mid - 1);
        node->right = inorderToBalanced(inorder, mid + 1, e);

        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        vector<int> inorder;

        normalBSttoInorder(root, inorder);
        return inorderToBalanced(inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
