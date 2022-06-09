/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k - (k/nums.size())*nums.size();
        reverse(nums, 0,nums.size()-k-1);
        reverse(nums, nums.size()-k ,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
    void reverse(vector<int>& nums, int low, int high)
    {
        while(low<high)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
};
// @lc code=end

