// it takes 1 step to reach cell 1 from neighbour cell 0's
// so the value of those cell 1s will be 1
// now we calculate distance of other cell 1s from the calculated cell 1s
// basically, push cell 0s in queue first
// then push cell 1s

class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& mat){
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
                    if(dx >= 0 && dy >= 0 && dx < n && dy < m && mat[dx][dy] == -1){
                        q.push({dx, dy});
                        mat[dx][dy] = mat[x][y] + 1;
                    }
                }
            }
        }
        return mat;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }
};