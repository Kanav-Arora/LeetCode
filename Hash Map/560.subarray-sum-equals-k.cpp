/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int count = 0, sum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            
            if(sum==k)
                count++;
            
            if(mp.count(sum-k))
            {
                count+=mp[sum-k];
            }
            
            mp[sum]++;;
        }
        
        return count;
    }
};
// @lc code=end

