/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
    int dp[101];

public:
    int solve(vector<int> &nums, int n)
    {
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + solve(nums, n - 2);
        int dont = solve(nums, n - 1);

        return dp[n] = max(pick, dont);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, n - 1);
    }
};
// @lc code=end
