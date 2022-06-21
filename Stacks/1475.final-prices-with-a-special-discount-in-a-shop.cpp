/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> s;
        vector<int> disc;
        for(int i = n-1; i>-1; i--)
        {
            if(s.empty())
                disc.push_back(0);
            else if(s.top()<=prices[i])
                disc.push_back(s.top());
            else
            {
                while(!s.empty() && s.top()>prices[i])
                    s.pop();
                if(s.empty())
                    disc.push_back(0);
                else if(s.top()<=prices[i])
                {
                    disc.push_back(s.top());
                }
            }
            s.push(prices[i]);
        }
        
        reverse(disc.begin(), disc.end());
        
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            ans.push_back(prices[i] - disc[i]);
        }
        
        return ans;
    }
};
// @lc code=end

