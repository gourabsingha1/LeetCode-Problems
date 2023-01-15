class Solution {
public:
    int parent[100001], rank[100001];
    void makeSet(int n){
        for (int i = 1; i <= n; i++)
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
    void Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
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
    }
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int res = 0, n = vals.size();
        vector<vector<int>> adj = createGraph(n, edges);
        makeSet(n);
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            m[vals[i]].push_back(i);
        }
        for(auto& [x, y] : m){
            for(int& node : y){
                for(int& neighbour : adj[node]){
                    if(vals[neighbour] > x) continue;
                    Union(node, neighbour);
                }
            }
            unordered_map<int, int> count;
            for(int& node : y){
                int it = findParent(node);
                count[it]++;
                res += count[it];
            }
        }

        return res;
    }
};