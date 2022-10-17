/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
public:
    bool DFS(vector<int> adjl[], vector<int>& arr, vector<bool> &vis, int node)
    {
        vis[node] = true;
        
        if(arr[node]==0)
            return true;
        
        bool flag = false;
        
        for(auto each : adjl[node])
            if(!vis[each])
                flag = flag || DFS(adjl,arr,vis,each);
        
        return flag;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        vector<int> adjl[arr.size()];
        
        for(int i=0; i<arr.size(); i++)
        {
            int prev = i-arr[i];
            int next = i+arr[i];
            
            if(prev>=0)
                adjl[i].push_back(prev);
            if(next<arr.size())
                adjl[i].push_back(next);
        }
        
        vector<bool> vis(arr.size(),false);
        
        return DFS(adjl,arr, vis,start);
    }
};
// @lc code=end

