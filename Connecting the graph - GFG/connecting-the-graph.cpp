//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(vector<bool> &vis, int i, vector<vector<int>> &adj){
        vis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(vis, it, adj);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& connections) {
        int res = -1;
        if(n > connections.size() + 1){
            return -1;
        }
        vector<vector<int>> adj = createGraph(n, connections);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(vis, i, adj);
                res++;
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends