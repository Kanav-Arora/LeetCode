/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> adj[rooms.size()];
        
        for(int i=0; i<rooms.size(); i++)
        {
            for(int j=0; j<rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        queue<int> q;
        vector<bool> vis(rooms.size(), false);
        
        q.push(0);
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            vis[front] = true;
            
            for(auto nbr : adj[front])
            {
                if(!vis[nbr])
                    q.push(nbr);
            }
        }
        
        for(int i=0; i<vis.size(); i++)
        {
            if(vis[i]==false)
                return false;
        }
        
        return true;
    }
};
// @lc code=end

