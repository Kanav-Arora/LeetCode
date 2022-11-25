/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
    int dp[101];
public:
    int solve(vector<int>& nums, int n)
    {
        if(n<0) return 0;
        
        if(dp[n]!=-1)   return dp[n];
        
        int pick = nums[n] + solve(nums,n-2);
        int dont = solve(nums,n-1);
        
        return dp[n] = max(pick,dont);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        
        vector<int> temp1(nums.begin()+1,nums.end());
        vector<int> temp2(nums.begin(), nums.end()-1);
        memset(dp,-1,sizeof(dp));
        int val1 = solve(temp1,temp1.size()-1);
        memset(dp,-1,sizeof(dp));
        int val2 = solve(temp2, temp2.size()-1);
        return max(val1, val2);
    }
};
// @lc code=end

