/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution
{
public:
    void DFS(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = true;
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                DFS(grid, vis, nrow, ncol);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
                DFS(grid, vis, i, 0);
            if (grid[i][n - 1] == 1)
                DFS(grid, vis, i, n - 1);
        }

        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
                DFS(grid, vis, 0, i);
            if (grid[m - 1][i] == 1)
                DFS(grid, vis, m - 1, i);
        }

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
    }
};
// @lc code=end
