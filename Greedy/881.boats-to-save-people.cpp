/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j=people.size()-1;
        int boats = 0;
        
        while(i<=j)
        {
            if(people[i]+people[j] <=limit)
            {
                i++; j--;
                boats++;
            }
            else
            {
                j--;
                boats++;
            }
        }
        
        return boats;
    }
};
// @lc code=end

