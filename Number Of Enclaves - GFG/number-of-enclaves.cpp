//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i, int j, vector<vector<int>>& grid, int &sum) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == -1){
            return 0;
        }
        if(!grid[i][j]) return 1;
        grid[i][j] = 0;
        sum++;

        return dfs(i-1, j, grid, sum) & dfs(i, j-1, grid, sum) & dfs(i+1, j, grid, sum) & dfs(i, j+1, grid, sum);
    }
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]){
                    int sum = 0;
                    if(dfs(i, j, grid, sum)){
                        res += sum;
                    }
                }
            }
        }
        return res;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends