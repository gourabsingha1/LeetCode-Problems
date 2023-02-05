//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bfs(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination){
        if(!grid[source.first][source.second]) return -1;
        int n = grid.size(), m = grid[0].size(), res = 0;
        queue<vector<int>> q;
        q.push({source.first, source.second});
        grid[source.first][source.second] = 1;
        vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while(q.size()){
            int t = q.size();
            while(t--){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                if(x == destination.first && y == destination.second){
                    return res;
                }
                for (int i = 0; i < dir.size(); i++)
                {
                    int dx = x + dir[i][0], dy = y + dir[i][1];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy]){
                        q.push({dx, dy});
                        grid[dx][dy] = 0;
                    }
                }
            }
            res++;
        }
        return -1;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        return bfs(grid, source, destination);
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends