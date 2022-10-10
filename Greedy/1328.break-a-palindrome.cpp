/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n < 2)
        {
            return "";
        }
        int flag = 0;

        for (int i = 0; i < n / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                flag = 1;
                palindrome[i] = 'a';
                break;
            }
        }
        if (flag == 0)
        {
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};
// @lc code=end
