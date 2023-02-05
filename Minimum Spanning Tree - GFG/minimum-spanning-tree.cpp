//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        int res = 0;
        vector<int> dist(n, 1e9), parent(n); // update with minimum distance
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[0] = 0;
        parent[0] = -1;
        pq.push({0, 0}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            res += prev;
            vis[u] = 1;
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(!vis[v] && dist[v] > wt){
                    dist[v] = wt;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends