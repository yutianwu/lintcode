class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.size() == 0 || B.size() == 0) return 0;

        int result = 0;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = (A[i] == B[j] ? 1 : 0);
                else {
                    if (A[i] == B[j])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = 0;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
