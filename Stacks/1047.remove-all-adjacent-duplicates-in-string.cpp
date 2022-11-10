/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s;
        for(auto i:str)
        {
            if(s.empty())
                s.push(i);
            else
            {
                if(s.top()==i)
                {
                    s.pop();
                }
                else
                    s.push(i);
            }
        }
        string ans;
        while(!s.empty())
            ans+=s.top(),s.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

