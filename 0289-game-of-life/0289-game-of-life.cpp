// board[i][j] = 2 (die next), 3 (live next)

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                for (int k = 0; k < dir.size(); k++)
                {
                    int dx = i + dir[k][0], dy = j + dir[k][1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                        cnt += (board[dx][dy] == 1 || board[dx][dy] == 2);
                    }
                }
                if(board[i][j]) {
                    if(cnt < 2 || cnt > 3) {
                        board[i][j] = 2;
                    }
                }
                else {
                    if(cnt == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};