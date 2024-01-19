// go from top to bottom placing queens if position is valid

class Solution {
public:
    bool isValid(int i, int j, int n, vector<string>& board) {
        // upper left
        int r = i, c = j;
        while(r >= 0 && c >= 0) {
            if(board[r--][c--] == 'Q') {
                return 0;
            }
        }
        // up
        r = i, c = j;
        while(r >= 0) {
            if(board[r--][c] == 'Q') {
                return 0;
            }
        }
        // upper right
        r = i, c = j;
        while(r >= 0 && c < n) {
            if(board[r--][c++] == 'Q') {
                return 0;
            }
        }
        return 1;
    }
    
    void helper(int i, int n, vector<string>& board, vector<vector<string>>& res) {
        if(i == n) {
            res.push_back(board);
            return;
        }
        
        for (int j = 0; j < n; j++)
        {
            if(isValid(i, j, n, board)) {
                board[i][j] = 'Q';
                helper(i + 1, n, board, res);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        helper(0, n, board, res);
        return res;
    }
};