/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
            We'll use binary search 
            we'll find lower bound and upper bound of the list
        */
        return {binary_search(nums,target,"FIRST"), binary_search(nums,target,"LAST")};

    }
    int binary_search(vector<int> nums, int target, string find)
    {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        int result = -1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                result = mid;
                (find=="FIRST") ? end = mid-1 : start = mid+1;
            }
            else if(nums[mid]>target)
                end  = mid-1;
            else
                start = mid+1;
        }
        return result;
    }
};
// @lc code=end

