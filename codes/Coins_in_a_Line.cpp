class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        if (n == 0) return false;
        vector<int> dp(n, true);
        for (int i = 2; i < n; i++) {
            dp[i] = !dp[i - 1] || !dp[i - 2];
        }
        return dp[n - 1];
    }
};