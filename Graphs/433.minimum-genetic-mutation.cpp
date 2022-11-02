/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
char choices[] = {'A','C','G','T'};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> vis(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({start,0});
        
        vis.erase(start);
        
        while(!q.empty())
        {
            auto front = q.front();
            string curr = front.first;
            int no = front.second;
            
            if(curr==end)
                return no;
            
            q.pop();
            
            for(int i=0; i<curr.length(); i++)
            {
                char org = curr[i];
                
                for(auto ch : choices)
                {
                    if(org==ch)
                        continue;
                    
                    curr[i] = ch;
                    if(vis.find(curr)!=vis.end())
                    {
                        vis.erase(curr);
                        q.push({curr,no+1});
                    }
                }
                curr[i] = org;
            }
        }
        
        return -1;
    }
};
// @lc code=end

