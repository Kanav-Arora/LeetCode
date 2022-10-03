/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        stack<pair<char, int>> stk;

        int time = 0;
        for (int i = 0; i < colors.length(); i++)
        {
            if (stk.empty())
            {
                stk.push({colors[i], i});
            }
            else
            {
                pair<char, int> top = stk.top();

                if (top.first == colors[i])
                {
                    if (neededTime[top.second] > neededTime[i])
                    {
                        time += neededTime[i];
                        continue;
                    }
                    else
                    {
                        stk.pop();
                        stk.push({colors[i], i});
                        time += neededTime[top.second];
                    }
                }
                else
                {
                    stk.push({colors[i], i});
                }
            }
        }

        return time;
    }
};
// @lc code=end
