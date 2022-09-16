/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> copy(grid.size(), vector<int> (grid[0].size()));
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                copy[i][j] = grid[i][j];
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        int time = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int,int> front = q.front();
                q.pop();
                
                int row = front.first;
                int col = front.second;
                int rowd[] = {0,-1,0,1};
                int cold[] = {-1,0,1,0};
                
                for(int k=0; k<4; k++)
                {
                    int nrow = row+ rowd[k];
                    int ncol = col+cold[k];
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && copy[nrow][ncol]==1)
                    {
                        copy[nrow][ncol]=2;
                        q.push({nrow, ncol});
                    }
                }
            }
            time++;
        }
        
        for(int i=0; i<copy.size(); i++)
        {
            for(int j=0; j<copy[0].size(); j++)
            {
                if(copy[i][j]==1)
                    return -1;
            }
        }
        
        if(time==0)
            return 0;
        
        return time-1;
    }
};
// @lc code=end

