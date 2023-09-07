class Solution {
public:
    vector<int> topoSort(int n, vector<int> adj[], vector<int>& quiet){
        vector<int> res(n), indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int u = 0; u < n; u++)
        {
            for(auto &v : adj[u]){
                indegree[v]++;
            }
            res[u] = u;
        }
        for (int u = 0; u < n; u++)
        {
            if(indegree[u] == 0){
                q.push(u);
            }
        }

        while(q.size()){
            int size = q.size();
            while(size--) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(quiet[res[v]] > quiet[res[u]]) {
                        res[v] = res[u];
                    }
                    if(--indegree[v] == 0){
                        q.push(v);
                    }
                }
            }
        }
        return res;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> res(n), adj[n];
        for (int i = 0; i < richer.size(); i++)
        {
            int u = richer[i][0], v = richer[i][1];
            adj[u].push_back(v);
        }
        return topoSort(n, adj, quiet);
    }
};