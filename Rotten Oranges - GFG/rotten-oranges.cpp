//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0, fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        vector<int> directions = {-1, 0, 1, 0, -1}; 
        while(q.size() && fresh){
            int size = q.size();
            while(size--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++){
                    int r = x + directions[i], c = y + directions[i+1];
                    if(r < 0 || c < 0 || r == n || c == m || !grid[r][c]){
                        continue;
                    }
                    q.push({r, c});
                    grid[r][c] = 0;
                    fresh--;
                }
            }
            res++;
        }
        if(fresh) return -1;
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends