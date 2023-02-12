class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n + 1), rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
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
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            int u = leftChild[i], v = rightChild[i];
            if(u >= 0){
                if(ds.Union(u, i) || vis[u]){
                    return 0;
                }
                vis[u] = 1;
            }
            if(v >= 0){
                if(ds.Union(v, i) || vis[v]){
                    return 0;
                }
                vis[v] = 1;
            }
        }
        int root = ds.findParent(0);
        for (int i = 1; i < n; i++)
        {
            if(root != ds.findParent(i)){
                return 0;
            }
        }
        return 1;
    }
};