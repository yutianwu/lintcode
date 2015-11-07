class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 && word.size() == 0) return true;
        if (board.size() == 0) return false;
        
        int rows = board.size();
        int cols = board[0].size();
        vector<bool> row(cols, false);
        vector<vector<bool>> visit(rows, row);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, word, 0, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, int row, int col, string word, int pos, vector<vector<bool> > &visit) {
        if (pos >= word.size()) 
            return true;
        
        if (board[row][col] != word[pos] || visit[row][col])
            return false;
        
        int direct[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        visit[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int x = row + direct[i][0];
            int y = col + direct[i][1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (dfs(board, x, y, word, pos + 1, visit)) {
                    visit[row][col] = false;
                    return true;
                }
            }
        }
  
        visit[row][col] = false;
        return false;
    }
};
