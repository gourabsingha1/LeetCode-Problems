//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DisjointSet{
public:
    int parent[100001], rank[100001];
    void makeSet(int n){
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    bool Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v){
            return 1;
        }
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        return 0;
    }
};

class Solution
{
	public:
    static bool sortbyvector(const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    }
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                edges.push_back({i, it[0], it[1]});
            }
        }
        sort(edges.begin(), edges.end(), sortbyvector);
        vector<int> parent(n);
        int cost = 0;
        DisjointSet DS;
        DS.makeSet(n);
        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(DS.findParent(u) != DS.findParent(v)){
                cost += wt;
                parent[u] = v;
                DS.Union(u, v);
            }
        }
        return cost;
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