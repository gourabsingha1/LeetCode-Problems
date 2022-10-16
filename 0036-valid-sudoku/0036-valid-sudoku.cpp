class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            unordered_map<char,int> mrow, mcol, m3x3;
            for(int j = 0; j < 9; j++){
                // row & col
                if(board[i][j] != '.'){
                    mrow[board[i][j]]++;
                    if(mrow[board[i][j]] > 1){
                        return 0;
                    }
                }
                if(board[j][i] != '.'){
                    mcol[board[j][i]]++;
                    if(mcol[board[j][i]] > 1){
                        return 0;
                    }
                }

                // 3x3
                int x = (i/3)*3 + (j/3), y = (i%3)*3 + j%3;
                // cout<<"("<<x<<","<<y<<") ";

                if(board[x][y] != '.'){
                    m3x3[board[x][y]]++;
                    if(m3x3[board[x][y]] > 1){
                        return 0;
                    }
                }
            }
            // cout<<endl;
        }
        return 1;
    }
};