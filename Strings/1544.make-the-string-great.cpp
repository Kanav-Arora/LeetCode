/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> stk;

        for (int i = 0; i < s.length(); i++)
        {
            if (stk.empty())
                stk.push(s[i]);
            else
            {
                char top = stk.top();

                if (tolower(top) == tolower(s[i]) && ((islower(top) && isupper(s[i])) || (isupper(top) &&
                                                                                          islower(s[i]))))
                {
                    stk.pop();
                }
                else
                    stk.push(s[i]);
            }
        }

        string ans = "";

        while (!stk.empty())
        {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};
// @lc code=end
