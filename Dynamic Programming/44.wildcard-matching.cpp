/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string text, string pattern)
    {
        int n = pattern.length();
        int m = text.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<int> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;

        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (pattern[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (pattern[i - 1] == '*')
                    curr[j] = curr[j - 1] | prev[j];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
// @lc code=end
