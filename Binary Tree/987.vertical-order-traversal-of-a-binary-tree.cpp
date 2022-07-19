/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> nodes;     // map<hd, map<level,nodes>>
        queue<pair<TreeNode *, pair<int, int>>> q; // pair<Node, pair<hd,leve>>

        q.push({root, {0, 0}});

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> frontnode = q.front();
            q.pop();

            TreeNode *node = frontnode.first;
            int hd = frontnode.second.first;
            int level = frontnode.second.second;

            nodes[hd][level].push_back(node->val);

            if (node->left)
                q.push({node->left, {hd - 1, level + 1}});

            if (node->right)
                q.push({node->right, {hd + 1, level + 1}});
        }

        for (auto i : nodes)
        {
            vector<int> temp;
            for (auto j : i.second)
            {
                vector<int> lhd = j.second;
                sort(lhd.begin(), lhd.end());

                for (auto k : lhd)
                    temp.push_back(k);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
// @lc code=end
