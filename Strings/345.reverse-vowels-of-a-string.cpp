/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        
        unordered_set<char> vis;
        vis.insert('a');
        vis.insert('e');
        vis.insert('i');
        vis.insert('o');
        vis.insert('u');
        vis.insert('A');
        vis.insert('E');
        vis.insert('I');
        vis.insert('O');
        vis.insert('U');
        
        for(int i=0; i<s.length(); i++)
        {
            if(vis.find(s[i])!=vis.end())
                vowels.push_back(s[i]);
        }
        
        reverse(vowels.begin(), vowels.end());
        
        int k = 0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(vis.find(s[i])!=vis.end())
            {
                s[i] = vowels[k];
                k++;
            }
        }
        
        return s;
    }
};
// @lc code=end

