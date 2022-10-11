/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        int ans = INT_MIN;

        while (!q.empty())
        {
            pair<int, int> front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;

            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for (int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && (grid[nrow][ncol] == 0 || grid[nrow][ncol] > grid[i][j] + 1))
                {
                    grid[nrow][ncol] = grid[i][j] + 1;
                    q.push({nrow, ncol});
                    ans = max(ans, grid[nrow][ncol]);
                }
            }
        }

        return ans >= 0 ? ans - 1 : -1;
    }
};
// @lc code=end
