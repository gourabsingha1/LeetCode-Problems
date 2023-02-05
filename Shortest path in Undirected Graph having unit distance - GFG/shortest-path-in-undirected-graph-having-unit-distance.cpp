//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> BFS(int src, int n, vector<int> adj[]){
        vector<int> dist(n, 1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(q.size()){
            int i = q.front();
            q.pop();
            for(auto &it : adj[i]){
                if(dist[it] > dist[i] + 1){
                    dist[it] = dist[i] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src){
        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return BFS(src, n, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends