/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        
        vector<int> adj[v];
        
        for(int i=0; i<graph.size(); i++)
        {
            int u = i;
            
            for(int j=0; j<graph[i].size(); j++)
            {
                int v = graph[i][j];
                
                adj[u].push_back(v);
            }
        }
        
        int color = 0;
        vector<int> col(v,-1);
        queue<int> q;
        for(int i=0; i<v; i++)
        {
            if(col[i]!=-1)  continue;
            
            q.push(i);
            col[i] = 0;
            
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                int color = col[front];

                for(auto nbr :  adj[front])
                {
                    if(col[nbr]==-1)
                    {
                        q.push(nbr);
                        col[nbr] = !color;
                    }
                    else if(col[nbr]==color)
                    {
                        return false;
                    }
                }
            }
            
        }
        
        
        return true;
    }
};
// @lc code=end

