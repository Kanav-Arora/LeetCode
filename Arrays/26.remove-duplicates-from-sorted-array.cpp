/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int left = 0;
        for(int right=1; right<nums.size(); right++)
        {
            if(nums[left]!=nums[right])
                left++;
            nums[left] = nums[right];
        }
        return left+1;

        
        /*
        int arr[101] = {0};
        int neg[101] = {0};
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>=0)
            {
            arr[nums[i]]++;
            }
            else
            {
                neg[nums[i]*(-1)]++;
            }
        }
        int count = 0;
        nums = {};
        for(int i=100; i>=0; i--)
        {
            if(neg[i]>0)
            {
                nums.push_back(-i);
                count++;
            }
        }
        for(int i=0; i<101; i++)
        {
            if(arr[i]>0)
            {
                nums.push_back(i);
                count++;
            }
        }
        return count;
        */
    }
};
// @lc code=end

