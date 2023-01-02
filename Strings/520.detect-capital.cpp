/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool alupper = true, allower = true, camel = true;

        for(int i=0; i<word.length(); i++)
        {
            if(i==0 && isupper(word[0]))    camel = true;

            if(isupper(word[i]))
            {
                if(i==0)    camel = true;
                else camel = false;
                allower = false;
            }
            else
            {
                alupper = false;
            }
        }

        return allower || alupper || camel;
    }
};
// @lc code=end

