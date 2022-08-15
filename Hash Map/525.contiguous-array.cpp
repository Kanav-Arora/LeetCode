/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        
        int start = -1, end = -1, sum=0;
        unordered_map<int,int> mapping;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(sum==0)
            {
                start = 0; end = i;
            }
            
            if(mapping.count(sum)==1)
            {
                if((i - mapping[sum] + 1 > end- start) || start==-1)
                {
                    start = mapping[sum]+1;
                    end = i;
                }
            }
            
            else
            {
                mapping[sum] = i;
            }
            
        }
        
        if(start==-1)
            return 0;
        
        return end-start+1;
    }
};
// @lc code=end

