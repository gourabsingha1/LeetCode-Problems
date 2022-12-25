class Solution {
public:
    void dfs(int i, int j, int n, int m, int sourceColor, int color, vector<vector<int>>& image){
        if(image[i][j] == sourceColor){
            image[i][j] = color;
        }
        else{
            return;
        }

        if(i > 0){
            dfs(i-1, j, n, m, sourceColor, color, image);
        }
        if(j > 0){
            dfs(i, j-1, n, m, sourceColor, color, image);
        }
        if(i < n-1){
            dfs(i+1, j, n, m, sourceColor, color, image);
        }
        if(j < m-1){
            dfs(i, j+1, n, m, sourceColor, color, image);
        }
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