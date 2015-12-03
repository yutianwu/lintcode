// 解法一:
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        vector<int> increment;
        for (int i = 1; i < prices.size(); i++)
            increment.push_back(prices[i] - prices[i - 1]);

        int result = 0;
        int cur_max = 0;
        for (int i = 0; i < increment.size(); i++) {
            cur_max = max(cur_max + increment[i], increment[i]);
            result = max(result, cur_max);
        }
        return result;
    }
};

// 解法二
// 思路就是每一个位置卖出股票所获得的最大收益，都是用该处的价钱减去它前面最低的价钱
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int low = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < low)
                low = prices[i];
            else
                max_profit = max(max_profit, prices[i] - low);
        }
        return max_profit;
    }
};
