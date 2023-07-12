// Reverse the graph, then return the topological sort in ascending order

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
            if(indegree[u] == 0){
                q.push(u);
            }
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> newGraph(n);
        for (int i = 0; i < n; i++)
        {
            for(auto &it : graph[i]){
                newGraph[it].push_back(i);
            }
        }

        TopologicalSortBFS TS;
        vector<int> res = TS.topoSort(n, newGraph);
        sort(res.begin(), res.end());
        return res;
    }
};