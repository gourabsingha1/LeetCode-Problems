// To find if one edge is critical, delete that edge and re-run the MST algorithm and see if the weight of the new MST increases.
// To find if one edge is non-critical (in any MST), include that edge to the accepted edge list and continue the MST algorithm, then see if the resulting MST has the same weight of the initial MST of the entire graph.

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

// **** Kruskals Algorithm Minimum Spanning Tree - O(elog(n)), O(n + e) ****
class KruskalsAlgoMST{
public:
    int kruskals(int includeEdge, int deleteEdge, int n, vector<vector<int>> edges){
        int cost = 0;
        vector<int> parent(n);
        DisjointSet DS(n);
        if(includeEdge != -1) {
            int u = edges[includeEdge][0], v = edges[includeEdge][1], wt = edges[includeEdge][2];
            cost += wt;
            DS.Union(u, v);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if(i == deleteEdge) continue;
            if(DS.findParent(u) != DS.findParent(v)){
                cost += wt;
                DS.Union(u, v);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (DS.findParent(i) != DS.findParent(0)) {
                return 1e6;
            }
        }
        return cost;
    }
};

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pseudoCritical;
        // edge = {u, v, wt, index}
        for (int i = 0; i < edges.size(); i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);

        KruskalsAlgoMST MST;
        int minCost = MST.kruskals(-1, -1, n, edges);
        for (int i = 0; i < edges.size(); i++)
        {
            int index = edges[i][3];
            if(MST.kruskals(-1, i, n, edges) > minCost) {
                critical.push_back(index);
            }
            else if(MST.kruskals(i, -1, n, edges) == minCost) {
                pseudoCritical.push_back(index);
            }
        }
        return {critical, pseudoCritical};
    }
};