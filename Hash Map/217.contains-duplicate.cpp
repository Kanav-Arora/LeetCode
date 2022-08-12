/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int i=0; i<nums.size(); i++)
            set.insert(nums[i]);
        
        return !(set.size()==nums.size());
    }
};
// @lc code=end

