//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> edges[], int src){
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                int u = i, v = edges[i][j][0], wt = edges[i][j][1];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }
        vector<int> distTo(n, 1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        distTo[src] = 0;
        pq.push({0, src});
        while(pq.size()){
            int dist = pq.top().first, prev = pq.top().second;
            pq.pop();
            for(auto &it : adj[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next] > dist + nextDist){
                    distTo[next] = dist + nextDist;
                    pq.push({distTo[next], next});
                }
            }
        }
        return distTo;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends