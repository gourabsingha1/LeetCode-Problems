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
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);
        vector<bool> res(queries.size());
        DisjointSet ds(n);

        int i = 0;
        for(auto& q : queries) {
            for ( ; i < edgeList.size() && edgeList[i][2] < q[2]; i++)
            {
                ds.Union(edgeList[i][0], edgeList[i][1]);
            }
            res[q[3]] = ds.findParent(q[0]) == ds.findParent(q[1]);
        }
        return res;
    }
};