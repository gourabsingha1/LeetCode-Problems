class Solution {
public:
    bool isValid(int x, int y, char num, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            // row
            if(board[i][y] == num) {
                return 0;
            }
            // col
            if(board[x][i] == num) {
                return 0;
            }
        }
        // 3 x 3
        int x1 = x / 3 * 3, y1 = y / 3 * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[x1 + i][y1 + j] == num) {
                    return 0;
                }
            }
        }
        return 1;
    }

    bool helper(vector<vector<char>>& board) {
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if(board[x][y] == '.') {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if(isValid(x, y, num, board)) {
                            board[x][y] = num;
                            if(helper(board)) {
                                return 1;
                            }
                        }
                    }
                    // you will reach here when you cannot fill up a cell
                    // set it to '.' for further operations
                    board[x][y] = '.';
                    return 0;
                }
            }
        }
        
        // you will reach here after filling up every cell
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};