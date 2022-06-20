/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        int n = students.size();
        for(int i=0; i<students.size(); i++)
        {
            q.push(students[i]);  
            s.push(sandwiches[n-1-i]);
        }
        
        int rotations = 0;
        
        while(!q.empty() && rotations<q.size())
        {
            if(q.front()==s.top())
            {
                q.pop();
                s.pop();
                rotations=0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }
        
        return q.size();
    }
};
// @lc code=end

