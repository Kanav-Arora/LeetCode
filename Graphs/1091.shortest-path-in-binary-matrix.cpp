/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;

        int n = grid.size();
        queue<pair<int, int>> q;
        int ans = 0;

        q.push({0, 0});

        while (!q.empty())
        {
            int cnt = q.size();

            while (cnt-- > 0)
            {
                auto front = q.front();
                q.pop();
                int i = front.first;
                int j = front.second;

                if (i == n - 1 && j == n - 1)
                    return ans + 1;

                int drow[] = {0, -1, -1, -1, 0, 1, 1, 1};
                int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};

                for (int k = 0; k < 8; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0)
                    {
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 2;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};
// @lc code=end
