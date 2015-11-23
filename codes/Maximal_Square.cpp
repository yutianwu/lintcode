class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int maxNum = 0;
        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            dp[i][0] = matrix[i][0];
            maxNum = max(maxNum, dp[i][0]);
        }
        for (int i = 0; i < cols; i++) {
            dp[0][i] = matrix[0][i];
            maxNum = max(maxNum, dp[0][i]);
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    maxNum = max(maxNum, dp[i][j]);
                }
            }
        }
        return maxNum * maxNum;
    }
};
