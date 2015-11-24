class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        int size = A.size();
        if (size == 0) return 0;
        
        vector<long long> dp(size + 1, 0);
        dp[1] = A[0];
        for (int i = 2; i <= size; i++) {
            dp[i] = max(dp[i - 1], A[i - 1] + dp[i - 2]);
        }
        return dp[size];    
    }
};
