//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int i, int V, bool &res, vector<bool> &vis, vector<int>adj[]){
        queue<pair<int, int>> q;
        vis[i] = 1;
        q.push({i, -1}); // first node doesn't have a parent node. so, -1
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto &it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node}); // it = node, node = parent node
                }
                else if(parent != it){ // the node is marked visited by some other way. this means that a cycle is formed
                    res = 1;
                    return;
                }
            }
        }
    }
    bool isCycle(int V, vector<int>adj[]){
        bool res = 0;
        vector<bool> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bfs(i, V, res, vis, adj);
                if(res) return 1;
            }
        }
        return 0;
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