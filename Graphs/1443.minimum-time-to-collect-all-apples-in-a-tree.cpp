/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution
{
private:
    bool solver(vector<int> adj[], vector<bool> has, int node, int &ans, vector<bool> &vis)
    {
        vis[node] = true;
        bool poss = false;
        for (auto ele : adj[node])
        {
            if (!vis[ele])
            {
                bool call = solver(adj, has, ele, ans, vis);
                if (call == true)
                    ans++;
                poss = poss || call;
            }
        }
        poss = poss || has[node];
        return poss;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                solver(adj, hasApple, i, ans, vis);
            }
        }

        return ans * 2;
    }
};
// @lc code=end
