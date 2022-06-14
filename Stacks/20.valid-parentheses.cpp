/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1)
            return false;
        
        stack<int> stk;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stk.push(ch);
                continue;
            }
                
            if(stk.empty() && (ch = ')' || ch == '}' || ch==']'))
                return false;
            if((ch==')' && stk.top()=='(')|| (ch=='}' && stk.top()=='{'|| (ch==']' && stk.top()=='[')))
                stk.pop();
            else
                return false;
        }
        
        if(stk.empty())
               return true;
        
        return false;
    }
};
// @lc code=end

