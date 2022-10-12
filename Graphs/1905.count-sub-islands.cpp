/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
public:
    bool DFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 2 || grid2[i][j] == 0)
            return true;

        if (grid1[i][j] == 0)
            return false;

        grid2[i][j] = 2;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        bool flag = true;
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            flag &= DFS(grid1, grid2, nrow, ncol);
        }

        return flag;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 1 && DFS(grid1, grid2, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};
// @lc code=end
