/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i=0; i<stones.size(); i++)
            q.push(stones[i]);
        
        while(q.size()>1)
        {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            
            if(s1==s2)
                continue;
            else 
                q.push(s1-s2);
        }
        
        return q.size()==0 ? 0 : q.top();
    }
};
// @lc code=end

