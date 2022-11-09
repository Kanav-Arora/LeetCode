/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner
{
public:
    stack<pair<int, int>> s;
    int count;
    StockSpanner()
    {
        count = 0;
    }

    int next(int price)
    {
        if (s.empty())
        {
            s.push({price, count});
            count++;
            return 1;
        }
        else if (s.top().first > price)
        {
            int val = count - s.top().second;
            s.push({price, count});
            count++;
            return val;
        }
        else
        {
            while (!s.empty() && s.top().first <= price)
                s.pop();
            if (s.empty())
            {
                s.push({price, count});
                count++;
                return count;
            }
            else
            {
                int val = count - s.top().second;
                s.push({price, count});
                count++;
                return val;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
