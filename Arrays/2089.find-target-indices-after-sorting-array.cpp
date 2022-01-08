/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */

// @lc code=start
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Using count sort
        int count=0, rank=0;
        vector<int> ans;
        for(int n : nums)
        {
            count += n==target;
            rank += n<target;
        }
        while(count--)  ans.push_back(rank++);
        return ans;
    }
};
// @lc code=end

