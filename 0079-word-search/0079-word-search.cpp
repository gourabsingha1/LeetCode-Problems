class Solution {
public:
    bool res = 0;
    void dfs(int i, int j, int k, vector<vector<char>>& board, string &word){
        if(k == word.size()){
            res = 1;
            return;
        }
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[k]){
            return;
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(i - 1, j, k + 1, board, word);
        dfs(i, j - 1, k + 1, board, word);
        dfs(i + 1, j, k + 1, board, word);
        dfs(i, j + 1, k + 1, board, word);
        board[i][j] = c;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0]){
                    dfs(i, j, 0, board, word);
                }
            }
        }
        return res;
    }
};