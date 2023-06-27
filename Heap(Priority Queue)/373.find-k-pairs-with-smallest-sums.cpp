/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pp> pq;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = nums1[i] + nums2[j];
                auto p = make_pair(sum, make_pair(nums1[i], nums2[j]));
                if (pq.size() < k)
                {
                    pq.push(p);
                }
                else if (sum < pq.top().first)
                {
                    pq.pop();
                    pq.push(p);
                }
                else
                    break;
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};
// @lc code=end
