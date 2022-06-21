/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int> > s;
        vector<int> smallerleft;
        int n = heights.size();
        
        for(int i=0; i<n; i++)
        {
            if(s.empty())
                smallerleft.push_back(0);
            else if(s.top().first<heights[i])
            {
                smallerleft.push_back(0);
            }
            else
            {
                while(!s.empty() && s.top().first>=heights[i])
                    s.pop();
                
                if(s.empty())
                    smallerleft.push_back(i);
                else if(s.top().first<heights[i])
                    smallerleft.push_back(i-s.top().second-1);
            }
            
            s.push({heights[i],i});
        }
        
        while(!s.empty())
            s.pop();
        
        vector<int> smallerright;
        
        for(int i=n-1; i>=0; i--)
        {
            if(s.empty())
                smallerright.push_back(0);
            else if(s.top().first<heights[i])
            {
                smallerright.push_back(0);
            }
            else
            {
                while(!s.empty() && s.top().first>=heights[i])
                    s.pop();
                
                if(s.empty())
                    smallerright.push_back(n-1-i);
                else if(s.top().first<heights[i])
                    smallerright.push_back(s.top().second-1-i);
            }
            
            s.push({heights[i],i});
        }
        reverse(smallerright.begin(), smallerright.end());
        vector<int> ans;
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            ans.push_back((smallerright[i] + smallerleft[i] +1)*heights[i]);
            maxi = max(ans[i],maxi);
        }
        
        return maxi;
    }
};
// @lc code=end

