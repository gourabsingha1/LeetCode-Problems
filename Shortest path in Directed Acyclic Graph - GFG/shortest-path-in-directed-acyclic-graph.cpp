//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector <int> dijkstra(int src, int n, vector<vector<int>> adj[]){
        vector<int> dist(n, 1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, i = pq.top().second;
            pq.pop();
            for(auto &it : adj[i]){
                int j = it[0], wt = it[1];
                if(dist[j] > prev + wt){
                    dist[j] = prev + wt;
                    pq.push({dist[j], j});
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
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        vector<vector<int>> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        return dijkstra(0, n, adj);
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