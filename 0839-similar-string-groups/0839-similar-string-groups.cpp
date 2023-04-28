class DisjointSet{
public:
    vector<int> parent, rank;
    int n;
    DisjointSet(int n){
        this->n = n;
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = 0;
                for (int k = 0; k < strs[0].size(); k++)
                {
                    if(strs[i][k] != strs[j][k]) {
                        cnt++;
                    }
                }
                if(cnt == 0 || cnt == 2){
                    ds.Union(i, j);
                }
            }
        }
        return ds.size();
    }
};