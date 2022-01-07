/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0; 
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j]) {
				i++;
			}
			else if(nums1[i]>nums2[j]) {
				j++;
			}
            else
            {
                answer.push_back(nums1[i]);
                
            }
        }

    }
};
// @lc code=end

