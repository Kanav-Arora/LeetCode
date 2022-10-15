/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            if (i == headID)
                continue;
            adj[manager[i]].push_back(i);
            adj[i].push_back(manager[i]);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});

        vector<bool> vis(n, false);
        int maxi = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front().first;
                int timetaken = q.front().second;
                vis[curr] = true;
                q.pop();
                int dur = informTime[curr] + timetaken;
                maxi = max(maxi, dur);
                for (auto a : adj[curr])
                {
                    if (!vis[a])
                        q.push({a, dur});
                }
            }
        }

        return maxi;
    }
};
// @lc code=end
