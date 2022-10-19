/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution
{
public:
    static bool comp(pair<int, string> a, pair<int, string> b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;

        for (auto each : words)
            mp[each]++;

        vector<pair<int, string>> v;

        for (auto each : mp)
        {
            v.push_back({each.second, each.first});
        }

        sort(v.begin(), v.end(), comp);

        vector<string> ans;

        int i = 0;
        while (i < k)
        {
            ans.push_back(v[i].second);
            i++;
        }

        return ans;
    }
};
// @lc code=end
