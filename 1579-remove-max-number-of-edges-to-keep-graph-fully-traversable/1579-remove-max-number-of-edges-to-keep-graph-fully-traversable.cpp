class DisjointSet{
public:
    vector<int> parent, rank;
    int n;
    DisjointSet(int n){
        this->n = n;
        parent.resize(n + 1), rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }

    bool Union(int u, int v){
        u = findParent(u), v = findParent(v);
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
        n--;
        return 0;
    }

    int size() {
        return n;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0, aliceEdges = 0, bobEdges = 0;
        sort(edges.rbegin(), edges.rend());
        DisjointSet ds1(n), ds2(n);
        for (auto &e : edges)
        {
            if(e[0] == 3) {
                if(ds1.Union(e[1], e[2])) {
                    res++;
                }
                else {
                    ds2.Union(e[1], e[2]);
                    aliceEdges++, bobEdges++;
                }
            }
            else if(e[0] == 2) {
                if(ds2.Union(e[1], e[2])) {
                    res++;
                }
                else {
                    bobEdges++;
                }
            }
            else if(e[0] == 1) {
                if(ds1.Union(e[1], e[2])) {
                    res++;
                }
                else {
                    aliceEdges++;
                }
            }
        }
        if(aliceEdges == n - 1 && bobEdges == n - 1) return res;
        return -1;
    }
};