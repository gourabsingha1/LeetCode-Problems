class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = '.';
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < board.size() && dy < board[0].size() && board[dx][dy] == 'X'){
                dfs(dx, dy, board);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'X'){
                    dfs(i, j, board);
                    res++;
                }
            }
        }
        return res;
    }
};