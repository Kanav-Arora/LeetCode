/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int ans = 0;

        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt-- > 0)
            {
                auto front = q.front();
                q.pop();

                int i = front.first;
                int j = front.second;

                if ((i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].size() - 1) && !(j == entrance[1] && i == entrance[0]))
                    return ans;

                int drow[] = {0, -1, 0, 1};
                int dcol[] = {-1, 0, 1, 0};

                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];

                    if (nrow >= 0 && nrow < maze.size() && ncol >= 0 && ncol < maze[0].size() && maze[nrow][ncol] == '.')
                    {
                        q.push({nrow, ncol});
                        maze[nrow][ncol] = '+';
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};
// @lc code=end
