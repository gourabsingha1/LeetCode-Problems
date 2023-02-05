//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        int res = 0;
        vector<int> parent(n);
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        parent[0] = -1;
        pq.push({0, 0}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            res += prev;
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(!vis[v]){
                    parent[v] = u;
                    pq.push({wt, v});
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