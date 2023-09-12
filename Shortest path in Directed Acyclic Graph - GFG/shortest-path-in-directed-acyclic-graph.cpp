//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// **** Shortest Path in DAG with Weights - O(n + e), O(n) ****
class ShortestPathDAGraph{
public:
    void tSortDFS(int u, vector<bool>& vis, vector<int>& st, vector<vector<int>> adj[]){
        vis[u] = 1;
        for(auto& it : adj[u]){
            int v = it[0];
            if(!vis[v]){
                tSortDFS(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }
    
    vector<int> topoSort(int n, vector<vector<int>> adj[]){
        vector<int> st;
        vector<bool> vis(n);
        for (int u = 0; u < n; u++)
        {
            if(!vis[u]){
                tSortDFS(u, vis, st, adj);
            }
        }
        // reverse(st.begin(), st.end());
        return st;
    }

    vector<int> shortestPath(int src, int n, vector<vector<int>> adj[]){
        vector<int> st = topoSort(n, adj);
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(st.size()){
            int u = st.back();
            st.pop_back();
            if(dist[u] != 1e9){
                for(auto& it : adj[u]){
                    int v = it[0], wt = it[1];
                    dist[v] = min(dist[v], dist[u] + wt);
                }
            }
        }
        for(auto& x : dist) {
            if(x == 1e9) x = -1;
        }
        return dist;
    }
};

class Solution {
  public:
     vector<int> shortestPath(int n, int M, vector<vector<int>>& edges){
        vector<vector<int>> adj[n];
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }
        ShortestPathDAGraph SP;
        return SP.shortestPath(0, n, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends