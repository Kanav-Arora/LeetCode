/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    void dfs_traversal(vector<vector<int>>& graph , vector<bool>& visited , int start){
        visited[start]=true;
        for(auto it : graph[start]){
            if(!visited[it]){
                dfs_traversal(graph , visited , it );
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)
            return -1;
        
        vector<vector<int>> graph(n);
        for(auto con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        vector<bool> visited(n ,false);
        int component=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                component++;
                dfs_traversal(graph , visited , i);
            }
        }
        return component-1;
    }
};
// @lc code=end

