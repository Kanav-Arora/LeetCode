/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
    int dp[1001];
public:
    int solve(vector<int>& cost, int n)
    {
        if(n<0) return 0;
        if(n==0 || n==1)    return cost[n];
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = cost[n] + min(solve(cost,n-1),solve(cost,n-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,n-1), solve(cost,n-2));
    }
};
// @lc code=end

