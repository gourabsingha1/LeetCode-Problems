class Solution {
public:
    void bfs(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!mat[i][j]){
                    q.push({i, j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        vector<int> dir = {0, 1, 0, -1, 0};
        while(q.size()){
            int t = q.size();
            while(t--){
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i], dy = y + dir[i + 1];
                    if(isValid(dx, dy, n, m) && mat[dx][dy] == -1){
                        q.push({dx, dy});
                        mat[dx][dy] = mat[x][y] + 1;
                    }
                }
            }
        }
    }
    bool isValid(int &i, int &j, int &n, int &m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        bfs(mat);
        return mat;
    }
};