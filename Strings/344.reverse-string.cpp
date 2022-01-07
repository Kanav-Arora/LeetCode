/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverse(vector<char>& s, int left, int right)
    {
        if(left>=right)             // base condition
            return;
        swap(s[left++],s[right--]);
        reverse(s,left,right);
    }

    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }
};
// @lc code=end

