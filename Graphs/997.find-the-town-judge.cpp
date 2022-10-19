/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adjl[n+1];
        vector<int> indegree(n+1,0);
        
        for(auto each : trust)
        {
            adjl[each[0]].push_back(each[1]);
            indegree[each[1]]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==n-1 && adjl[i].empty())
                return i;
        }
        
        return -1;
    }
};
// @lc code=end

