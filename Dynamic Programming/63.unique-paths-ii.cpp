/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        vector<int> row(n, 0);
        row[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    row[j] = 0;
                else if (i == 0 && j == 0)
                    row[0] = 1;
                else
                {
                    int left = 0;

                    if (j > 0)
                        left = row[j - 1];

                    row[j] = dp[j] + left;
                }
            }

            dp = row;
        }

        return dp[n - 1];
    }
};
// @lc code=end
