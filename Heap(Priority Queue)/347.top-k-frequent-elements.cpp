/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

class comp
{
  public:
    bool operator()(const pair<int,int> a, const pair<int,int> b)
    {
        return a.first>b.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int, int> mapping;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> minHeap;  // freq, number
        
        for(int i=0; i<nums.size(); i++)
        {
            mapping[nums[i]]++;
        }
        
        int i=0;
        map<int,int>::iterator it;
        it = mapping.begin(); 
        while(it!=mapping.end() && i<k)
        {
            minHeap.push({it->second, it->first});
            it++; i++;
        }
        
        while(it!=mapping.end())
        {
            if(it->second>minHeap.top().first)
            {
                minHeap.pop();
                minHeap.push({it->second, it->first});
                it++;
            }
            else
                it++;
        }
        
        vector<int> res;
        for(int i=0; i<k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};
// @lc code=end

