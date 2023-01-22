//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int baseX, baseY;
    void dfs(int i, int j, vector<pair<int,int>> &v, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        v.push_back({baseX - i, baseY - j});
        dfs(i-1, j, v, grid);
        dfs(i, j-1, v, grid);
        dfs(i+1, j, v, grid);
        dfs(i, j+1, v, grid);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]){
                    vector<pair<int,int>> v;
                    baseX = i, baseY = j;
                    dfs(i, j, v, grid);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends