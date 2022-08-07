/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mh;
        
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            if(mh.size()<k)
            {
                mh.push(nums[i]);
            }
            
            else if(mh.top()<nums[i])
            {
                mh.pop();
                mh.push(nums[i]);
            }
        }
        
        return mh.top();
    }
};
// @lc code=end

