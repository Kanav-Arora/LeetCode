/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
struct compare
{
  bool operator()(pair<int,int> const a, pair<int,int> const b)
  {
      if(a.first==b.first)
            return a.second<b.second;
      return a.first>b.first;
  }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;      // number,freq
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> q;
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        for(auto &i: mp)
            q.push({i.second,i.first});
        
        vector<int> ans;
        while(!q.empty())
        {
            int freq = q.top().first;
            int ele = q.top().second;
            for(int i=0; i<freq; i++)
                ans.push_back(ele);
            q.pop();
        }
        
        return ans;
    }
};
// @lc code=end

