class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        if (A.size() == 0) return 0;
        vector<vector<bool>> visit(A.size(), vector<bool>(A[0].size(), false));
        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                dp[i][j] = search(A, visit, dp, i, j);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
    
    int search(vector<vector<int>> &A, vector<vector<bool>> &visit, vector<vector<int>> &dp, int x, int y) {
        if (visit[x][y]) return 0;
        if (dp[x][y] != 0) return dp[x][y];
        
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};

        visit[x][y] = true;
        int result = 1;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny =  y+ dy[i];
            if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny] > A[x][y]) {
                result = max(result, 1 + search(A, visit,dp, nx, ny));
            }
        }
        visit[x][y] = false;
        dp[x][y] = result;
        return result;
    }
};
