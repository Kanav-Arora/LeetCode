/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
private:
    int solver(vector<int> &coins, int am, int i, vector<vector<int>> &dp)
    {
        if (am == 0)
            return 0;
        if (i < 0)
            return 1e9;
        if (dp[i][am] != -1)
            return dp[i][am];
        int dont = solver(coins, am, i - 1, dp);
        int pick = 1e9;
        if (coins[i] <= am)
            pick = 1 + solver(coins, am - coins[i], i, dp);
        return dp[i][am] = min(pick, dont);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solver(coins, amount, n - 1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
// @lc code=end
