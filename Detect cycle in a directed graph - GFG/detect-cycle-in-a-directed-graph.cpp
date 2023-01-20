//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[]){
        vis[i] = 1;
        dfsVis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                if(dfs(it, vis, dfsVis, adj)){
                    return 1;
                }
            }
            else if(dfsVis[it]){
                return 1;
            }
        }
        dfsVis[i] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]){
        vector<bool> vis(V, 0); // to mark all time visited paths
        vector<bool> dfsVis(V, 0); // to mark the current visited path
        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends