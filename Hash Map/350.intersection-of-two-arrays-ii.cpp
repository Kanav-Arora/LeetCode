/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int,int> hash;
        
        for(int i=0; i<n1; i++)
            hash[nums1[i]]++;
        
        vector<int> ans;
        
        for(int i=0; i<n2; i++)
        {
            if(--hash[nums2[i]]>=0)
                ans.push_back(nums2[i]);
        }
        
        return ans;
    }
};
// @lc code=end

