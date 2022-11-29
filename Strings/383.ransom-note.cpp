/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        
        for(int i=0; i<magazine.length(); i++)
        {
            mp[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.length(); i++)
        {
            if(mp[ransomNote[i]]<=0)    return false;
            mp[ransomNote[i]]--;
        }
        
        return true;
    }
};
// @lc code=end

