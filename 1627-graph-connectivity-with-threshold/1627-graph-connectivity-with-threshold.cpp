class Solution {
public:
    int parent[10001], rank[10001];
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        makeSet(n);
        vector<bool> res;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sqrt(i); j++)
            {
                if(i % j == 0){
                    if(j > threshold){
                        Union(i, j);
                    }
                    if(i / j > threshold){
                        Union(i, i / j);
                    }
                }
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0], v = queries[i][1];
            res.push_back(findParent(u) == findParent(v));
        }
        return res;
    }
};