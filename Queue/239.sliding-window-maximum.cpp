/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        
        for(int i=0; i<k; i++)
        {
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        ans.push_back(nums[q.front()]);
        
        for(int i=k; i<nums.size(); i++)
        {
            
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                q.pop_back();
            }
            
            q.push_back(i);
            
            ans.push_back(nums[q.front()]);
        }
        
        
        return ans;
    }
};
// @lc code=end

