/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    void DFS(int node,int n,vector<int> adj[], vector<int> path, vector<vector<int>> &ans)
    {
        path.push_back(node);
        
        if(node==n)
        {
            ans.push_back(path);
            return;
        }
        
        for(auto nbr : adj[node])
        {
            DFS(nbr,n, adj, path, ans);
        }
            
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        
        for(int i=0; i<graph.size(); i++)
        {
            for(int j=0; j<graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>> ans;
        vector<int> path;
        
        DFS(0,graph.size()-1, adj, path, ans);
        
        return ans;
    }
};
// @lc code=end

