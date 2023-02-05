//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int M = 1e9 + 7;
    int dijkstras(int src, int n, vector<vector<int>> adj[]){
        vector<int> dist(n, 1e9), ways(n);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, i = pq.top().second;
            pq.pop();
            for(auto &it : adj[i]){
                int j = it[0], wt = it[1];
                if(dist[j] > prev + wt){
                    dist[j] = prev + wt;
                    pq.push({dist[j], j});
                    ways[j] = ways[i];
                }
                else if(dist[j] == prev + wt){
                    ways[j] = (ways[j] + ways[i]) % M;
                }
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        return dijkstras(0, n, adj);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends