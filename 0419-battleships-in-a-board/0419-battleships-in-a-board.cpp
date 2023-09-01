// iterating from top left to bottom right and checking only
// up and left cell ensures weather it is a part of current battleship or not

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.' || i > 0 && board[i - 1][j] == 'X' || j > 0 && board[i][j - 1] == 'X') continue;
                res++;
            }
        }
        return res;
    }
};