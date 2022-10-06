/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
public:
    unordered_map<string, map<int, string>> m;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin())
            return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
