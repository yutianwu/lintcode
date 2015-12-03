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
