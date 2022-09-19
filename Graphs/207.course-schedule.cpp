/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto k : prerequisites)
        {
            int v = k[0];
            int u = k[1];
            
            adj[u].push_back(v);
        }
        
        int V = numCourses;
        int indegree[V];
        
        for(int i=0; i<V; i++)
            indegree[i] = 0;

    for (int i = 0; i < V; i++)
    {
        for (auto k : adj[i])
        {
            indegree[k]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    if (q.size() == 0)
        return false;

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        count++;
        q.pop();

        for (auto i : adj[front])
        {
            indegree[i]--;

            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (count != V)
        return false;

    return true;
    }
};
// @lc code=end

