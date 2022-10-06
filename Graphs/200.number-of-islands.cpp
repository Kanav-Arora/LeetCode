/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '2';

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && grid[nrow][ncol] == '1')
                DFS(grid, nrow, ncol);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    DFS(grid, i, j);
                }
            }
        }

        return num;
    }
};
// @lc code=end
