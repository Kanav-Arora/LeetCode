/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mapping;
        
        for(int i=0; i<cpdomains.size(); i++)
        {
            string freqstr = cpdomains[i].substr(0,cpdomains[i].find(" "));
            int freq = stoi(freqstr);
            string domain = cpdomains[i].substr(cpdomains[i].find(" ")+1,cpdomains[i].length());
            while(domain.find(".")!=string::npos)
            {
                mapping[domain]+=freq;
                domain = domain.substr(domain.find(".")+1,domain.length());
            }
            mapping[domain]+=freq;
        }
        
        unordered_map<string,int>:: iterator it = mapping.begin();
        
        vector<string> ans;
        while(it!=mapping.end())
        {
            ans.push_back(to_string(it->second)+" "+it->first);
            it++;
        }
        
        return ans;
    }
};
// @lc code=end

