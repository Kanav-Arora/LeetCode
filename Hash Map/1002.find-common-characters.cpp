/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<int,int> mapping;
        
        for(int i=0; i<26; i++)
            mapping[i] = INT_MAX;
        
        for(auto a :  words)
        {
            int hash[26] = {0};
            
            for(auto x : a)
            {
                hash[x - 'a']++;
            }
            
            for(int i=0; i<26; i++)
            {
                mapping[i] = min(mapping[i],hash[i]);
            }
        }
        
        vector<string> ans;
        
        for(int i=0; i<26; i++)
        {
            while(mapping[i])
            {
                ans.push_back(string(1,i + 'a'));
                mapping[i]--;
            }
        }
        
        return ans;
    }
};
// @lc code=end

