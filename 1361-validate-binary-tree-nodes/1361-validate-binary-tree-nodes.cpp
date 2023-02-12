class Solution {
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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        makeSet(n);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            int u = leftChild[i], v = rightChild[i];
            if(u >= 0){
                if(Union(u, i) || vis[u]){
                    return 0;
                }
                vis[u] = 1;
            }
            if(v >= 0){
                if(Union(v, i) || vis[v]){
                    return 0;
                }
                vis[v] = 1;
            }
        }
        int root = findParent(0);
        for (int i = 1; i < n; i++)
        {
            if(root != findParent(i)){
                return 0;
            }
        }
        return 1;
    }
};