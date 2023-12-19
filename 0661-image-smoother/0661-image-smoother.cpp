// brute force

class Solution {
public:
    vector<int> dir[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    
    void formResult(int x, int y, vector<vector<int>>& img, vector<vector<int>>& res) {
        int total = img[x][y], cnt = 1;
        for (int i = 0; i < 8; i++)
        {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if(dx >= 0 && dy >= 0 && dx < img.size() && dy < img[0].size()) {
                total += img[dx][dy];
                cnt++;
            }
        }
        res[x][y] = total / cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int> (n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                formResult(i, j, img, res);
            }
        }
        return res;
    }
};