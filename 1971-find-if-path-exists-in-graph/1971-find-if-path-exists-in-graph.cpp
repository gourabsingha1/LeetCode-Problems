class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &storeDfs){
        storeDfs.push_back(node);
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, storeDfs);
            }
        }
        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return 1;
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> storeDfs;
                dfs(i, vis, adj, storeDfs);
                int found = 0;
                for(auto &x : storeDfs){
                    if(x == source || x == destination){
                        found++;
                    }
                    if(found == 2) return 1;
                }
            }
        }
        return 0;
    }
};