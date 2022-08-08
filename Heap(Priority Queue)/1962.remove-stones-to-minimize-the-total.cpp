/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        
        for(int i=0; i<piles.size(); i++)
        {
            maxHeap.push(piles[i]);
        }
        
        for(int i=0; i<k; i++)
        {
            int maxi = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(ceil((float)maxi/2));
        }
        
        
        int sum = 0;
        while(!maxHeap.empty())
        {
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        
        return sum;
    }
};
// @lc code=end

