/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        if (graph.size() == 1)
            return 0;

        int finalState = (1 << graph.size()) - 1;
        queue<pair<int, pair<int, int>>> q; // {node,{dist,bit mask}}
        set<pair<int, int>> vis;            // track {node,bit mask}

        for (int i = 0; i < graph.size(); i++)
        {
            q.push({i, {0, 1 << i}});
            vis.insert({i, 1 << i});
        }

        while (!q.empty())
        {
            auto p = q.front();
            int node = p.first;
            int dist = p.second.first;
            int mask = p.second.second;

            q.pop();

            for (auto nbr : graph[node])
            {
                int new_mask = (mask | (1 << nbr));

                if (new_mask == finalState)
                    return dist + 1;
                else if (vis.count({nbr, new_mask}))
                    continue;
                else
                {
                    q.push({nbr, {dist + 1, new_mask}});
                    vis.insert({nbr, new_mask});
                }
            }
        }

        return 0;
    }
};
// @lc code=end
