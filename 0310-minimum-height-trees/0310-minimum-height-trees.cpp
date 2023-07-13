// Delete leaves one by one levelwise. Return remaining nodes

// **** Topological Sort (BFS) | Kahn's Algorithm - O(n + e), O(n) ****
class TopologicalSortBFS{
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res, indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int u = 0; u < n; u++)
        {
            for(auto &v : adj[u]){
                indegree[v]++;
            }
        }
        for (int u = 0; u < n; u++)
        {
            if(indegree[u] == 1){
                q.push(u);
            }
        }
        while(q.size()){
            res.clear();
            int size = q.size();
            while(size--) {
                int u = q.front();
                q.pop();
                res.push_back(u);
                for(auto &v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        TopologicalSortBFS TS;
        return TS.topoSort(n, adj);
    }
};