/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<int> adj[], vector<bool> &vis, int node)
    {
        vis[node] = true;
        
        for(auto k: adj[node])
        {
            if(!vis[k])
                DFS(adj,vis,k);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count= 0;
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                else if(isConnected[i][j]==1)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        vector<bool> vis(n+1, false);
        
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                DFS(adj, vis, i);
                count++;
            }
        }
        
        return count;
    }
};
// @lc code=end

