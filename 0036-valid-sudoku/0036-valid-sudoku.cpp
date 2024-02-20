// an element should not appear more than once in a row/col/3x3

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            unordered_map<char,int> mrow, mcol, m3x3;
            for(int j = 0; j < 9; j++){
                // row & col
                if(board[i][j] != '.'){
                    if(mrow[board[i][j]]++){
                        return 0;
                    }
                }
                if(board[j][i] != '.'){
                    if(mcol[board[j][i]]++){
                        return 0;
                    }
                }

                // 3 x 3
                int x = (i / 3) * 3 + (j / 3), y = (i % 3) * 3 + j % 3;
                // cout<<"("<<x<<","<<y<<") ";
                if(board[x][y] != '.'){
                    if(m3x3[board[x][y]]++){
                        return 0;
                    }
                }
            }
            // cout<<endl;
        }
        return 1;
    }
};