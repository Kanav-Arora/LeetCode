/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
bool comp(vector<int> &v1, vector<int> &v2)
{
    return ((v1[0] * v1[0]) + (v1[1] * v1[1])) < ((v2[0] * v2[0]) + (v2[1] * v2[1]));
}

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), comp);

        vector<vector<int>> closest;

        for (int i = 0; i < k; i++)
            closest.push_back(points[i]);

        return closest;
    }
};
// @lc code=end
