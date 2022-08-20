/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(int i=0; i<strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
        for(auto &a: mp)
        {
            ans.push_back(a.second);
        }
        
        return ans;
    }
};
// @lc code=end

