//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class TopologicalSortDFS{
public:
    void dfs(int u, vector<bool> &vis, vector<int> &st, vector<vector<int>> &adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> st;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        reverse(st.begin(), st.end());
        return st;
    }
};
class Solution{
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
    int kosaraju(int n, vector<vector<int>> &adj){
        int res = 0;
        vector<vector<int>> revAdj(n);
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                revAdj[it].push_back(i);
            }
        }
        TopologicalSortDFS Topo;
        vector<int> topo = Topo.topoSort(n, adj);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[topo[i]]){
                res++;
                dfs(topo[i], vis, revAdj);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends