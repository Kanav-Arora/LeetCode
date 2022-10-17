/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> answer(n,-1);
        
        vector<int> redLs[n];
        vector<int> blueLs[n];
        
        for(auto each : redEdges)
            redLs[each[0]].push_back(each[1]);
        for(auto each : blueEdges)
            blueLs[each[0]].push_back(each[1]);
        
        queue<pair<int,int>> q;         // node, color
        
        q.push({0,1});      // 1 is for red color
        q.push({0,-1});     // 0 is for blue color
        vector<pair<int,int>> res(n,{INT_MAX,INT_MAX});
        res[0] = {0,0};
        int currdst = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                auto [node,color] = q.front();
                q.pop();
                
                if(color==-1)
                {
                    for(auto each : blueLs[node])
                    {
                        if(res[each].second>currdst+1)
                        {
                            q.push({each,1});
                            res[each].second = currdst+1;
                        }
                    }
                }
                else if(color==1)
                {
                    for(auto each : redLs[node])
                    {
                        if(res[each].first>currdst+1)
                        {
                            q.push({each,-1});
                            res[each].first = currdst+1;
                        }
                    }
                }
            }
            currdst++;
        }
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            int mini=min(res[i].first,res[i].second);
            ans[i]=(mini==INT_MAX) ? -1 : mini;
        }
        return ans;
    }
};
// @lc code=end

