/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        while (nums > 0)
        {
            if (nums >= 1000)
            {
                for (int i = 0; i < (nums / 1000); i++)
                    ans += 'M';
                nums = nums % 1000;
            }
            else if (nums >= 500)
            {
                if (nums / 100 == 5)
                {
                    ans += "D";
                    nums = nums % 100;
                }
                else if (nums / 100 == 9)
                {
                    ans += "CM";
                    nums = nums % 100;
                }
                else if (nums / 100 > 5)
                {
                    ans += "D";
                    nums -= 500;
                }
            }
            else if (nums >= 100)
            {
                if (nums / 100 == 4)
                {
                    ans += "CD";
                    nums = nums % 100;
                }
                else
                {
                    for (int i = 0; i < (nums / 100); i++)
                        ans += 'C';
                    nums = nums % 100;
                }
            }
            else if (nums >= 50)
            {
                if (nums / 10 == 5)
                {
                    ans += "L";
                    nums = nums % 10;
                }
                else if (nums / 10 == 9)
                {
                    ans += "XC";
                    nums = nums % 10;
                }
                else if (nums / 10 > 5)
                {
                    ans += "L";
                    nums = nums - 50;
                }
            }
            else if (nums >= 10)
            {
                if (nums / 10 == 4)
                {
                    ans += "XL";
                    nums = nums % 10;
                }
                else
                {
                    for (int i = 0; i < (nums / 10); i++)
                        ans += 'X';
                    nums = nums % 10;
                }
            }
            else if (nums >= 5)
            {
                if (nums == 9)
                {
                    ans += "IX";
                    nums = nums % 1;
                }
                else if (nums == 5)
                {
                    ans += "V";
                    nums = nums % 1;
                }
                else
                {
                    ans += "V";
                    nums = nums - 5;
                }
            }
            else
            {
                if (nums == 4)
                {
                    ans += "IV";
                    nums = nums % 1;
                }
                else
                {
                    for (int i = 0; i < (nums / 1); i++)
                        ans += 'I';
                    nums = nums % 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
