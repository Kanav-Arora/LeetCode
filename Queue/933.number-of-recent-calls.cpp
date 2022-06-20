/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter {
public:
    queue<int> recents;
    RecentCounter() {
    }
    
    int ping(int t) {
        recents.push(t);
        while(recents.front() < (t - 3000))
            recents.pop();
        return recents.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

