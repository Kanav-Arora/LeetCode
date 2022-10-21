/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(nums[i]) && abs(i-mp[nums[i]])<=k)
            {
                return true;
            }
            else
                mp[nums[i]] = i;
        }
        
        return false;
    }
};
// @lc code=end

