/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution
{
public:
    vector<int> parent;

    int find(int a) { return parent[a] == a ? a : find(parent[a]); }
    void unite(int a, int b) { parent[find(a)] = find(b); }

    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, vector<int>> rowmap, colmap;
        for (int i = 0; i < stones.size(); i++)
        {
            rowmap[stones[i][0]].push_back(i);
            colmap[stones[i][1]].push_back(i);
        }

        for (int i = 0; i < stones.size(); i++)
            parent.push_back(i);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j : rowmap[stones[i][0]])
                unite(i, j);
            for (int j : colmap[stones[i][1]])
                unite(i, j);
        }

        unordered_set<int> unique;
        for (int n : parent)
            unique.insert(find(n));
        return stones.size() - unique.size();
    }
};
// @lc code=end
