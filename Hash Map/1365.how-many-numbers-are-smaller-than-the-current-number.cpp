/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> mapping;
        
        for(int i=0; i<nums.size(); i++)
        {
            mapping[nums[i]]++;
        }
        
        map<int,int>:: iterator it = mapping.begin();
        int sum = it->second;
        it->second = 0;
        it++;
        while(it!=mapping.end())
        {
            int val=it->second;
            it->second = sum;
            sum+=val;
            it++;
        }
        
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
            ans.push_back(mapping[nums[i]]);
        
        return ans;
    }
};
// @lc code=end

