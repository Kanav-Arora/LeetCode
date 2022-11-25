/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(r*c!=m*n)    return mat;
        
        vector<vector<int>> ans;
        int col = 0;

        vector<int> temp;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int curr = mat[i][j];
                temp.push_back(curr);
                col++;
                
                if(col==c)
                {
                    col = 0;
                    ans.push_back(temp);
                    temp.clear();
                }
                
            }
        }
        
        return ans;
    }
};
// @lc code=end

