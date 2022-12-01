/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        int first = 0, second = 0;
        
        for(int i=0; i<s.length(); i++)
        {
            char ch = tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                if(i<s.length()/2)
                    first++;
                else
                    second++;
            }
        }
        return first==second;
    }
};
// @lc code=end

