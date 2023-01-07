//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int i, int parent, bool &res, vector<bool> &vis, vector<int> adj[]){
        vis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(it, i, res, vis, adj);
            }
            else if(it != parent){
                res = 1;
                return;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool res = 0;
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                dfs(i, -1, res, vis, adj);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends