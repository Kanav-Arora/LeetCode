/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxis;
        int maxi = INT_MIN;
        int n = height.size();
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi,height[i]);
            maxis.push_back(maxi);
        }
        
        maxi = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(maxi,height[i]);
            maxis[i] = min(maxis[i],maxi);
        }
        
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            maxis[i] = maxis[i] - height[i];
            sum+=maxis[i];
        }
        
        return sum;
    }
};
// @lc code=end

