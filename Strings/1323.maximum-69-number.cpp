/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        string val = to_string(num);
        
        for(int i=0; i<val.length(); i++)
        {
            if(val[i]=='6')
            {
                val[i] = '9';
                break;
            }
        }
        
        return stoi(val);
    }
};
// @lc code=end

