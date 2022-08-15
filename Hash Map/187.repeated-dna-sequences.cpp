/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mapping;
        vector<string> ans;
        if(s.length()<=10)
            return ans;
        
        for(int i=0; i<=s.length()-10; i++)
        {
            string sub = s.substr(i,10);
            cout<<sub<<endl;
            mapping[sub]++;
        }
        
        unordered_map<string,int> :: iterator it = mapping.begin();
        
        
        while(it!=mapping.end())
        {
            if(it->second>1)
                ans.push_back(it->first);    
            it++;
        }
        return ans;
    }
};
// @lc code=end

