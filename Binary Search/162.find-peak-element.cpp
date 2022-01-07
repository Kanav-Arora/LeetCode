/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start<end)
        {
            int mid1 = start + (end-start)/2;
            int mid2 = mid1 + 1;
            if(nums[mid1]<nums[mid2])
            {
                start = mid2;
            }
            else
                end = mid1;
        }
        return start;
    }
};
// @lc code=end

