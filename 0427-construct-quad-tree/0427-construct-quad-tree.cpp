class Solution {
public:
    Node* helper(int r, int c, int n, vector<vector<int>>& grid) {
        Node* node = new Node(grid[r][c], 1);
        if(check(r, c, n, grid)){
            return node;
        }
        node->isLeaf = 0, n /= 2;
        node->topLeft = helper(r, c, n, grid);
        node->topRight = helper(r, c + n, n, grid);
        node->bottomLeft = helper(r + n, c, n, grid);
        node->bottomRight = helper(r + n, c + n, n, grid);
        return node;
    }
    bool check(int r, int c, int n, vector<vector<int>>& grid){
        for (int i = r; i < r + n; i++)
        {
            for (int j = c; j < c + n; j++)
            {
                if(grid[i][j] != grid[r][c]){
                    return 0;
                }
            }
        }
        return 1;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(0, 0, n, grid);
    }
};