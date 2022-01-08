/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int mid = 0;
        int last = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[last]!=val)
            {
                swap(nums[mid],nums[last]);
                last++;
                mid++;
            }
            else
            {
                last++;
            }
        }
        return mid;

    }
};
// @lc code=end

