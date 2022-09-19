/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto k : prerequisites)
        {
            adj[k[1]].push_back(k[0]);
        }
        
        vector<int> indegree(numCourses, 0);
        
        for(int i =0; i<numCourses; i++)
        {
            for(auto k: adj[i])
            {
                indegree[k]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;
        if(q.empty())
        {
            return ans;
        }
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto k : adj[front])
            {
                indegree[k]--;
                
                if(indegree[k]==0)
                {
                    q.push(k);
                }
            }
        }
        
        if(ans.size()!=numCourses)
        {
            ans.clear();
        }
        
        return ans;
    }
};
// @lc code=end

