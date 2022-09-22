/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        
        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1,0);
        
        for(int i=0; i<n+1; i++)
        {
            if(color[i])
                continue;
            
            else
            {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                
                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    
                    int curr = color[front];
                    int todo = curr==1 ? 2 : 1;
                    for(auto nbr :  adj[front])
                    {
                        if(color[nbr]==curr)
                            return false;
                        else if(!color[nbr])
                        {
                            color[nbr] = todo;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
// @lc code=end

