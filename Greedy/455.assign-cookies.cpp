/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(),g.end(), greater());
        sort(s.begin(),s.end(), greater());
        
        int i = 0, j =0;
        
        while(i<g.size() && j<s.size())
        {
            if(s[j]>=g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return count;
    }
};
// @lc code=end

