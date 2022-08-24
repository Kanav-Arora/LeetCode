/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        vector<int> v;
        for(int i=1; i<n; i++)
        {
            fac = fac*i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans = "";
        k = k-1;
        
        while(true)
        {
            int index = k/fac;
            ans+=to_string(v[index]);
            v.erase(v.begin()+index);
            if(v.size()==0)
                break;
            k = k%fac;
            fac = fac/v.size();
        }
        
        return ans; 
    }
};
// @lc code=end

