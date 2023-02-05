//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src){
        vector<int> dist(n, 1e9);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src}); // dist, node
        while(st.size()){
            auto it = *st.begin();
            int prev = it.first, i = it.second;
            st.erase(it);
            for(auto &it : adj[i]){
                int j = it[0], wt = it[1];
                if(dist[j] > prev + wt){
                    if(dist[j] != 1e9){ // edge check
                        st.erase({dist[j], j}); // longer distance not needed
                    }
                    dist[j] = prev + wt;
                    st.insert({dist[j], j});
                }
            }
        }
        return dist;
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