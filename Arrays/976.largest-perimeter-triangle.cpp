/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i > 1; i--)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
                return nums[i] + nums[i - 1] + nums[i - 2];
        }

        return 0;
    }
};
// @lc code=end
