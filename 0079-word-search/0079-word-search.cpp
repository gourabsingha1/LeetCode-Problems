class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    bool dfs(int x, int y, int k, vector<vector<char>>& board, string& word){
        if(k == word.size()){
            return 1;
        }
        board[x][y] ^= 257;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < board.size() && dy < board[0].size() && board[dx][dy] == word[k]){
                if(dfs(dx, dy, k + 1, board, word)) {
                    return 1;
                }
            }
        }
        board[x][y] ^= 257;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0] && dfs(i, j, 1, board, word)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};