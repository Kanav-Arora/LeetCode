/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void helper(int index, string s, vector<string> temp, vector<vector<string>> &ans)
    {
        if(index==s.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j = index; j<s.length(); j++)
        {
            if(isPalindrome(s,index,j))
            {
                temp.push_back(s.substr(index,j+1-index));
                helper(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0,s,temp,ans);
        
        return ans;
    }
};
// @lc code=end

