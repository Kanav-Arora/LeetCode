/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>> board, vector<vector<bool>> &v, int i, int j)
    {
        v[i][j] = false;
        
        int rowd[] = {0,-1,0,1};
        int cold[] = {-1,0,1,0};
        
        for(int k=0; k<4; k++)
        {
            int nrow = i +rowd[k];
            int ncol = j+ cold[k];
            
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='O' && v[nrow][ncol]==true)
            {
                v[nrow][ncol] = false;
                dfs(board,v,nrow,ncol);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> v(board.size(), vector<bool> (board[0].size(), true));
        bool flag = false;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='X')
                    v[i][j] = false;
                if(board[i][j]=='O')
                    flag = true;
            }
        }
        
        if(!flag || (board.size()==1 || board[0].size()==1))
            return;
        
        for(int i=0; i<board.size(); i+=board.size()-1)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='O')
                {
                    dfs(board,v, i,j);
                }
            }
        }
        
        for(int j=0; j<board[0].size(); j+=board[0].size()-1)
        {
            for(int i=0; i<board.size(); i++)
            {
                if(board[i][j]=='O')
                {
                    dfs(board,v,i,j);
                }
            }
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(v[i][j]==true)
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

