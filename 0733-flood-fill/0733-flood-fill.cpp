class Solution {
public:
    void dfs(int i, int j, int n, int m, int sourceColor, int color, vector<vector<int>>& image){
        if(i < 0 || j < 0 || i == n || j == m || image[i][j] != sourceColor){
            return;
        }
        image[i][j] = color;

        dfs(i-1, j, n, m, sourceColor, color, image);
        dfs(i, j-1, n, m, sourceColor, color, image);
        dfs(i+1, j, n, m, sourceColor, color, image);
        dfs(i, j+1, n, m, sourceColor, color, image);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size(), sourceColor = image[sr][sc];
        if(sourceColor != color){
            dfs(sr, sc, n, m, sourceColor, color, image);
        }
        return image;
    }
};