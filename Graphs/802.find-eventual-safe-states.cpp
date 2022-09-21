/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(),0);
        
        vector<int> adj[graph.size()];
        
        for(int i=0; i<graph.size(); i++)
        {
            for(int j=0; j<graph[i].size(); j++)
            {
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i=0; i<graph.size(); i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto nbr: adj[front])
            {
                indegree[nbr]--;
                
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
// @lc code=end

