/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool helper(string s, string t)
    {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> mapping;
        for(int i=0; i<s.size(); i++)
        {
            if(mapping.count(s[i])==0 || mapping[s[i]]==t[i])
            {
                mapping[s[i]] = t[i];
                continue;
            }
                
            
            return false;
        }
        
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
    }
};
// @lc code=end

