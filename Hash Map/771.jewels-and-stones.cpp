/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mapping;
        for(int i=0; i<stones.length(); i++)
        {
            mapping[stones[i]]++;
        }
        
        int count=0;
        for(int i=0; i<jewels.length(); i++)
        {
            count+=mapping[jewels[i]];
        }
        
        return count;
    }
};
// @lc code=end

