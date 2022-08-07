/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mh;
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        for(int i=0; i<rows; i++)
        {
            int sum=0;
            for(int j=0; j<cols; j++)
            {
                sum+=mat[i][j];
            }
            
            mh.push({sum,i});
        }
        
        vector<int> ans;
        
        for(int i=0; i<k; i++)
        {
            ans.push_back(mh.top().second);
            mh.pop();
        }
        
        return ans;
    }
};
// @lc code=end

