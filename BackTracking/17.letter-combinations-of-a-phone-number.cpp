/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    void solve(string digits, int i, int n, string comb, vector<string> &ans)
    {
        if(i==n)
        {
        ans.push_back(comb);
        return;
    }
        if(digits[i]-'0'>=2 && digits[i]-'0'<=6)
        {
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+1+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+2+97), ans);
        } 
        else if(digits[i]-'0'==7)
        {
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+1+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+2+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-1)*3+97), ans);
        }
        else if(digits[i]-'0'==8)
        {
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+1+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+2+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-1)*3+97), ans);
        }
        else if(digits[i]-'0'==9)
        {
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+1+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-2)*3+2+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-1)*3+97), ans);
            solve(digits,i+1,n, comb + char(((digits[i]-'0')-1)*3+1+97), ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(n==0)
            return ans;
        solve(digits,0,n,"",ans);
        
        return ans;
    }
};
// @lc code=end

