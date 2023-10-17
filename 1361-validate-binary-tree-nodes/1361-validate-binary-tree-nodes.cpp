// **** Disjoint set ****
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

    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]); // path compression
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
        return ds.size() == 1;
    }
};