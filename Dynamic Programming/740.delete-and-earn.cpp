/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
public:
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int currele = nums[i];
        int currsum = nums[i];
        int index = i + 1;

        while (index < nums.size() && nums[index] == currele)
        {
            currsum += currele;
            index++;
        }

        while (index < nums.size() && nums[index] == currele + 1)
            index++;

        return dp[i] = max(currsum + solve(nums, index, dp), solve(nums, i + 1, dp));
    }

    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
// @lc code=end
