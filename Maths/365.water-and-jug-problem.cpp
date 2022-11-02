/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return targetCapacity%__gcd(jug1Capacity,jug2Capacity) == 0 && targetCapacity<=jug1Capacity+jug2Capacity; 
    }
};
// @lc code=end

