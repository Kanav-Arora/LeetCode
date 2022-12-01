/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        vector<int> row(n,-1);
        row[0] = 1;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)    row[0] =1;
                else
                {
                    int left = 0;

                    if(j>0) left = row[j-1];

                    row[j] = dp[j] + left;
                }
            }

            dp = row;
        }

        return dp[n-1];
    }
};
// @lc code=end

