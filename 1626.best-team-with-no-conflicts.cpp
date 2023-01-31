/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution
{
private:
    int solver(vector<int> &ages, vector<int> &scores, int ind, int prev, vector<vector<int>> &dp)
    {
        if (ind == ages.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        int dont = solver(ages, scores, ind + 1, prev, dp);
        int pick = INT_MIN;
        if (prev == -1 || ages[prev] == ages[ind] || scores[prev] <= scores[ind])
            pick = scores[ind] + solver(ages, scores, ind + 1, ind, dp);
        return dp[ind][prev + 1] = max(dont, pick);
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> temp; // ages, scores
        int n = scores.size();
        for (int i = 0; i < n; i++)
        {
            temp.push_back({ages[i], scores[i]});
        }
        sort(temp.begin(), temp.end());

        scores.clear();
        ages.clear();

        for (auto i : temp)
        {
            ages.push_back(i.first);
            scores.push_back(i.second);
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solver(ages, scores, 0, -1, dp);
    }
};
// @lc code=end
