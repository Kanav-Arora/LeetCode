/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occ;
        for(int i=0; i<arr.size(); i++)
            occ[arr[i]]++;
        
        unordered_map<int,int> :: iterator it = occ.begin();
        unordered_map<int,int> no_of_occ;
        while(it!=occ.end())
        {
            no_of_occ[it->second]++;
            it++;
        }
        
        it = no_of_occ.begin();
        
        while(it!=no_of_occ.end())
        {
            if(it->second>1)
                return false;
            it++;
        }
        
        return true;
    }
};
// @lc code=end

