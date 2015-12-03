/*
 思路就是将问题分成两部分,我们使用一个数组forward存储第一次交易的最大利润，使用一个数组
 backward存储第二次交易的最大利润。
 那么forward[i]表示prices[0...i]这一段内一次交易能获得的最大利润.
 backward[i]表示prices[i...n]这一段内一次交易能获得的最大利润。
 结果就是将每一处的两部分相加，得到的最大的利润即为所求。
*/
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;

        vector<int> forward(prices.size(), 0);
        int max_profit = 0;
        int low = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < low)
                low = prices[i];
            else
                max_profit = max(max_profit, prices[i] - low);
            forward[i] = max_profit;
        }

        vector<int> backward(prices.size(), 0);
        max_profit = 0;
        int high = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i] > high)
                high = prices[i];
            else
                max_profit = max(max_profit, high - prices[i]);
            backward[i] = max_profit;
        }

        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            result = max(result, forward[i] + backward[i]);
        }
        return result;
    }
};
