/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].length();
        int count = 0;
        for(int i=0; i<len; i++)
        {
            string temp = "";

            for(auto a : strs)
                temp+=a[i];
            string copy = temp;
            sort(temp.begin(), temp.end());
            if(copy!=temp)  count++;
        }

        return count;
    }
};
// @lc code=end

