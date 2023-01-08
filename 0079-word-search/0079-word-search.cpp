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
        board[i][j] ^= 257;
        dfs(i - 1, j, k + 1, board, word);
        dfs(i, j - 1, k + 1, board, word);
        dfs(i + 1, j, k + 1, board, word);
        dfs(i, j + 1, k + 1, board, word);
        board[i][j] ^= 257;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(i, j, 0, board, word);
            }
        }
        return res;
    }
};